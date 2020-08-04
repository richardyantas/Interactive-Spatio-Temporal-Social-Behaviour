// particle 

#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<shader.h>      // cause geometry shaders required!
#include<math.h>
#include<vector>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

const unsigned int SCR_WIDTH_ = 1000;
const unsigned int SCR_HEIGHT_ = 600;

// We need the vectors defined on city vector<> builings  random 1 - 5   events to go to get food  risk factors
// We need to choose buildings to be hospital and other to be a shopping center to get food.

enum medicalstatus{NONINFECTED,INFECTEDNONSYMPTOMS,INFECTED};  // To use colors for that  green, yellow, red
enum labor{POLICE,CITINEST,DOCTOR};

class particle
{
    int id;
    int address;
    int infected;
    medicalstatus status;
    labor profession;
};


class particle
{
    private:

    std::vector<glm::vec3> vertices;
    unsigned int VAO;
    unsigned int VBO;
    Shader *pshader;
    float radius;
    glm::vec3 center;
    glm::vec3 target;
    glm::vec3 move;

    public:

    particle(float x = 0.0f, float y = 0.0f, float z = 0.0f, float radius = 100.0f)
    {
        pshader = new Shader("../particle.vs","../particle.fs","../particle.gs");
        //pshader = new Shader("../particle.vs","../particle.fs");
        center = glm::vec3(( 1. / SCR_WIDTH_ )*x,( 1. / SCR_HEIGHT_ )*y, 0.0f );   // Transform from world to gl
        //this->radius = ( 1. / SCR_WIDTH_ ) * radius;                              // Transform from world to gl

        this->radius = 0.01;
        center = glm::vec3(0.0f,0.0f,0.0f);
        target = glm::vec3(0.5f,0.5f,0.0f);
        move = center;
    }

    void init()
    {
        vertices.push_back(glm::vec3( 0.5f,  0.5f, -0.0f));
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBufferData( GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3), glm::value_ptr(vertices[0]), GL_STATIC_DRAW );
        //glBufferData( GL_ARRAY_BUFFER, indices.size()*sizeof(glm::uvec3), glm::value_ptr(indices[0]), GL_STATIC_DRAW );
        // position attribute
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);  // The first 0 indicate the location = 0 in vertex shader, if you texture coords 5 * sizeof
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        glBindVertexArray(0);
    }

    void render(const glm::mat4 &view)
    {
        pshader->use();
        glBindVertexArray(VAO);
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::vec3 u = glm::normalize(target-move);
        double err = glm::distance(move,target); 
        if(  err > 0.1 )
        {
            move = move + float(0.0001)*u;
        }
        model = glm::scale( model, glm::vec3( 1.0f, 1.0f, 1.0f ) );
        model = glm::translate(model, move ); //?? delta or the end
        //float angle = 20.0f ;
        //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.1f));
        pshader->setMat4("model", model);
        pshader->setMat4("view", view);
        pshader->setFloat("u_cRadius",radius);
        //glDrawElements(GL_LINE_STRIP, (GLsizei)indices.size()*3, GL_UNSIGNED_INT, NULL);    
        glDrawArrays( GL_POINTS, 0, vertices.size() );
        //glDrawArrays(GL_TRIANGLES, 0, 36);
        //glDrawArrays(GL_LINE_STRIP, 0, vertices.size()-12 );
        //glDrawArrays(GL_TRIANGLE_FAN, 0, 36);
        //glDrawArrays(GL_LINE_STRIP, 0, 24);
        //glDrawArrays( GL_TRIANGLE_STRIP, 0, 1 );
    }

    void done()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);   
    }
};