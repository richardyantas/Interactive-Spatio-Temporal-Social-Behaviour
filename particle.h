#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<shader.h>      // cause geometry shaders required!
#include<math.h>
#include<vector>
#include<stdlib.h> 
#include<time.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"common.h"
//const unsigned int SCR_WIDTH_ = 1000;
//const unsigned int SCR_HEIGHT_ = 600;
// We need the vectors defined on city vector<> builings  random 1 - 5   events to go to get food  risk factors
// We need to choose buildings to be hospital and other to be a shopping center to get food.
// shopping center, kind of money, air 
// Asumptions 0.8 people follow the rules of clean 
// risk factor, shoes, handle, timeOutside breathing 

//extern std::map<std::string,std::vector<glm::vec3>> singular;
//extern std::map<std::string,std::vector<std::vector<glm::vec3>>> multiple;
/*
glm::vec3    center;
glm::vec3    target;
glm::vec3    move;
*/
//center = glm::vec3(( 1. / SCR_WIDTH_ )*x,( 1. / SCR_HEIGHT_ )*y, 0.0f );   // Transform from world to gl
//this->radius = ( 1. / SCR_WIDTH_ ) * radius;                              // Transform from world to gl
//target mtarget;
// building <> home
// position achis even if he is protected, time very important 
 // not necessarily  -> teoria de redes dinamicas, obj: ver como evolucion en el tiempo para cada escenario y acciones que se tomen

enum status{NONINFECTED,INFECTEDNONSYMPTOMS,INFECTED};  // To use colors for that  green, yellow, red
enum labor{POLICE,CITIZEN,DOCTOR};
enum target{HOME, SHOPPING};


class particle
{
    public:
    unsigned int vao;
    unsigned int vbo;
    glm::vec3 mposition;
    glm::vec3 mtarget;
    glm::vec3 color;
    status mstatus;
    labor  mlabor;
    int id;
    int idBuilding; 
    //Shader *pshader;
    float radius;

    particle(glm::vec3 _position = glm::vec3(0.0f,0.0f,0.0f),status _status = NONINFECTED,labor _labor=CITIZEN ){
        mstatus = _status;
        color   = glm::vec3(0.0f,0.0f,0.8f);
        mlabor  = _labor;
        //mtarget = HOME;
        //pshader = new Shader("../particle.vs","../particle.fs","../particle.gs");
        this->radius = 0.001;
    }
    void config()
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData( GL_ARRAY_BUFFER, sizeof(glm::vec3), glm::value_ptr( this->mposition), GL_STATIC_DRAW );
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        glBindVertexArray(0);
    }

    void render(const glm::mat4 &view, Shader *s)
    {        
        glBindVertexArray(vao);
        glm::mat4 model = this->update();;
        s->setVec3("ourColor",this->color);
        s->setMat4("model", model);
        s->setMat4("view", view);
        s->setFloat("u_cRadius",this->radius);
        glDrawArrays( GL_POINTS, 0, 1 );
        glBindVertexArray(0);     
    }

    glm::mat4 update()
    {
        if(mstatus == INFECTED)            color = glm::vec3(1,0,0);
        if(mstatus == NONINFECTED)         color = glm::vec3(0,0,1);
        if(mstatus == INFECTEDNONSYMPTOMS) color = glm::vec3(1,1,0);

        glm::mat4 model = glm::mat4(1.0f);
        /*
        glm::vec3 u = glm::normalize(target-move);
        double err = glm::distance(move,target);
        if(err > 0.1)
            move = move + float(0.0001)*u;
        model = glm::scale( model, glm::vec3( 1.0f, 1.0f, 1.0f ) );
        model = glm::translate(model, move ); //?? delta or the end
        */
        return model;
    }

    void done()
    {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
    }
};