#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<shader.h>
#include<camera.h>
#include<math.h>
#include<vector>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


float f(float x, float y)
{
    //return sin(x*2.0f*3.141526f) * sin(y*2.0f*3.141526f) * 0.1f;
    return 0.0f;
}

//Shader baseShader("../base.vs","../base.fs");

class base
{
    private:

    std::vector<glm::vec3> vertices;
    std::vector<glm::uvec3> indices;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    Shader *pshader;

    public:
    base(){
        pshader = new Shader("../base.vs","../base.fs");
    }
    void generate_grid(int N, std::vector<glm::vec3> &vertices, std::vector<glm::uvec3> &indices)
    {
        
        for (int j=0; j<=N; ++j) 
        {
            for (int i=0; i<=N; ++i)
            {
                float x = (float)i/(float)N;
                float y = (float)j/(float)N;
                float z = f(x, y);
                vertices.push_back(glm::vec3(x, y, z));
            }
        }

        for (int j=0; j<N; ++j) 
        {
            for (int i=0; i<N; ++i)
            {
                int row1 = j * (N+1);
                int row2 = (j+1) * (N+1);  

                // triangle 1
                indices.push_back(glm::uvec3(row1+i, row1+i+1, row2+i+1)); 

                // triangle 2
                indices.push_back(glm::uvec3(row1+i, row2+i, row2+i+1)); 
            }
        }
        
    }

    void init()
    {
        generate_grid(10,vertices,indices);
        
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBufferData( GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3), glm::value_ptr(vertices[0]), GL_STATIC_DRAW );
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glBufferData( GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(glm::uvec3), glm::value_ptr(indices[0]), GL_STATIC_DRAW );
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
        //model = glm::scale( model, glm::vec3( 1.0f, 1.0f, 1.0f ) );
        model = glm::translate(model, glm::vec3( 0.0f,  0.0f,  0.0f));
        //float angle = 20.0f ;
        //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        pshader->setMat4("model", model);
        pshader->setMat4("view", view);
        //glDrawElements(GL_LINE_STRIP, (GLsizei)indices.size()*3, GL_UNSIGNED_INT, NULL);
        glDrawElements(GL_TRIANGLES, (GLsizei)indices.size()*3, GL_UNSIGNED_INT, NULL);
    }

    void done()
    {
        delete pshader;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        
    }
};