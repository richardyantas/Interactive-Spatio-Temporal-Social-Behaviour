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
const unsigned int SCR_WIDTH_ = 1000;
const unsigned int SCR_HEIGHT_ = 600;
// We need the vectors defined on city vector<> builings  random 1 - 5   events to go to get food  risk factors
// We need to choose buildings to be hospital and other to be a shopping center to get food.
// shopping center, kind of money, air 
// Asumptions 0.8 people follow the rules of clean 
// risk factor, shoes, handle, timeOutside breathing 
enum status{NONINFECTED,INFECTEDNONSYMPTOMS,INFECTED};  // To use colors for that  green, yellow, red
enum labor{POLICE,CITIZEN,DOCTOR};
enum target{HOME, SHOPPING};
enum typebuilding{COMMON,SHOPPINGCENTER,HOSPITAL};
//extern std::map<std::string,std::vector<glm::vec3>> singular;
//extern std::map<std::string,std::vector<std::vector<glm::vec3>>> multiple;
glm::vec3 getAverage(const std::vector<glm::vec3> &pol)
{
    glm::vec3 p=glm::vec3(0.0,0.0,0.0);
    for(int i=0;i<pol.size();i++)
    {
        p=p+pol[i];
    }
    return p/float(pol.size());
}

class building
{
    public:
    building(){};
    int id;
    typebuilding t;
    glm::vec3 position;
    // not necessarily  -> teoria de redes dinamicas, obj: ver como evolucion en el tiempo para cada escenario y acciones que se tomen
};


std::vector<glm::vec3> randomPosition(glm::vec3 centrum, int num)
{
    std::vector<glm::vec3> setPos(num);
    float r;
    float theta;
    //t.resize(num);
    for(int i=0;i<num;i++)
    {
        r      = 0.003;//* 1/5 * (rand() % 5 );
        theta  = 1.0/5 * ( rand() % 10 )*3.14;
         std::cout << "r:  " << r << "theta: " << theta << std::endl; 
        setPos[i] = centrum + glm::vec3(r*cos(theta),r*sin(theta),0.0f);

    }
    return setPos;
}

class particle
{
    public:
    glm::vec3 position;
    int id;
    int address; // building <> home
    status mstatus;  // position achis even if he is protected, time very important 
    labor  mlabor;
    //target mtarget;
    glm::vec3 mtarget;
    //float radius;
    glm::vec3 color;
    /*
    glm::vec3    center;
    glm::vec3    target;
    glm::vec3    move;
    */
    //center = glm::vec3(( 1. / SCR_WIDTH_ )*x,( 1. / SCR_HEIGHT_ )*y, 0.0f );   // Transform from world to gl
    //this->radius = ( 1. / SCR_WIDTH_ ) * radius;                              // Transform from world to gl
    particle(){
        //this->radius = 0.01;
        mstatus = NONINFECTED;
        color   = glm::vec3(0.0f,0.0f,0.8f);
        mlabor  = CITIZEN;
        //mtarget = HOME;
    }
    particle(glm::vec3 position_initial)
    {
        this->position = position_initial;
        //this->radius = 0.01;
        mstatus = NONINFECTED;
        color   = glm::vec3(0.0f,0.0f,0.8f);
        mlabor  = CITIZEN;
        //mtarget = HOME;
        /*
        center = glm::vec3(0.0f,0.0f,0.0f);
        target = glm::vec3(0.5f,0.5f,0.0f);
        move = center;
        */
       
    };

    glm::mat4 update()
    {
        if(mstatus == INFECTED) color = glm::vec3(1,0,0);
        if(mstatus == NONINFECTED) color = glm::vec3(0,0,1);
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
};


void setup(std::vector<std::vector<glm::vec3>> &rep,int num)
{
    // floy warshall shotest paths - home -> shopping center
    rep.resize(num);
    //targets.resize(num);
    for(int i=0;i<num;i++)
    {
        building mbuilding;
        mbuilding.id = 0;
        mbuilding.position = getAverage(multiple["buildings"][i]);
        int numParticles = rand() % 3 + 1;
        rep[i]=randomPosition(mbuilding.position,numParticles);
    }
    return;
}


class population
{
    private:
    
    std::vector<unsigned int> vaos;
    std::vector<unsigned int> vbos;    
    std::vector< std::vector <particle> > particlesGroup;
    int numParticles;
    Shader *pshader;
    float radius;

    public:
    population()
    {
        pshader = new Shader("../particle.vs","../particle.fs","../particle.gs");
        srand (time(NULL));
        //int num = 500;
        int num = 500;
        particlesGroup.resize(num);
        std::vector< std::vector <glm::vec3> > pos;
        //std::vector< std::vector <glm::vec3> > targets;
        setup(pos,num);
        
        numParticles = 0;
        for(int i=0;i<pos.size();i++)
        {
            vector<particle> group;
            for(int j=0;j<pos[i].size();j++)
            {
                particle p;
                p.position = pos[i][j];
                //p.mtarget  = targets[i][j]; 
                group.push_back(p);
                numParticles++;
            }
            particlesGroup.push_back(group);
        }
            
        this->radius = 0.001;
    }

    void init()
    {
        vaos.resize(numParticles);
        vbos.resize(numParticles);
        for(int i=0,z=0;i<particlesGroup.size();i++)
        {
            for(int j=0;j<particlesGroup[i].size();j++,z++)
            {
                glGenVertexArrays(1, &vaos[z]);
                glBindVertexArray(vaos[z]);
                glGenBuffers(1, &vbos[z]);
                glBindBuffer(GL_ARRAY_BUFFER, vbos[z]);
                glBufferData( GL_ARRAY_BUFFER, sizeof(glm::vec3), glm::value_ptr( particlesGroup[i][j].position), GL_STATIC_DRAW );
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0); 
                glBindVertexArray(0);
            }
        }
    }

    void render(const glm::mat4 &view)
    {
        pshader->use();
        for(int i=0,z=0;i<particlesGroup.size();i++)
        {
            for(int j=0;j<particlesGroup[i].size();j++,z++)
            {
                glBindVertexArray(vaos[z]);
                glm::mat4 model = particlesGroup[i][j].update();;
                pshader->setVec3("ourColor",particlesGroup[i][j].color);
                pshader->setMat4("model", model);
                pshader->setMat4("view", view);
                pshader->setFloat("u_cRadius",this->radius);
                glDrawArrays( GL_POINTS, 0, 1 );
                glBindVertexArray(0);  
                //particlesGroup[i][j].render();
                
            } 
        }
    }

    void done()
    {
        for(int i=0;i<vaos.size();i++)
        {
          glDeleteVertexArrays(1, &vaos[i]);
          glDeleteBuffers(1, &vbos[i]);
        } 
    }
};


