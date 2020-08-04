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
#include"particle.h"
#include"common.h"

const unsigned int SCR_WIDTH_ = 1000;
const unsigned int SCR_HEIGHT_ = 600;

class building;
class particle;
class population;

std::vector<glm::vec3> randomPosition(glm::vec3 centrum, int num);
void setup(std::vector<std::vector<glm::vec3>> &rep,int num);

enum typebuilding{COMMON,SHOPPINGCENTER,HOSPITAL};

static int ind = 0;
static int idSquare=0;
class building
{
    public:
    int id;
    int idSquare;
    typebuilding type;
    std::vector<glm::vec3> vertices;
    glm::vec3 mcentrum;
    building* parent;

    building()
    {
        parent = NULL;
        type = COMMON;
        id = ind;
        idSquare = ind;
        mcentrum = getAverage(multiple["buildings"][ind]);  
        vertices = multiple["buildings"][ind];
        ind++;      
    };
    glm::vec3 getAverage(const std::vector<glm::vec3> &b)
    {
        glm::vec3 p=glm::vec3(0.0,0.0,0.0);
        for(int i=0;i<b.size();i++)
        {
            p=p+b[i];
        }
        return p/float(b.size());
    }
};



/*
bool cmpx(glm::vec3 a, glm::vec3 b)
{
    return a.x < b.x;
}

bool cmpy(glm::vec3 a, glm::vec3 b)
{
    return a.y < b.y;
}


/*
class scenario
{
    // Set all the initial condition and some paremeter for the simulation such as infected people.
    public:
    std::vector<building> buildings;
    std::vector<particle> infectedPeople;
    std::vector<particle> nosymptoms;

    scenario()
    {

    };

};
*/


std::vector<particle> randomParticles(glm::vec3 centrum, int num)
{
    std::vector<particle> family(num);
    float r,theta;
    for(int i=0;i<num;i++)
    {
        r      = 0.002;//* 1/5 * (rand() % 5 );
        theta  = 1.0/5 * ( rand() % 10 )*3.14;
        family[i].mposition = centrum + glm::vec3(r*cos(theta),r*sin(theta),0.0f);
        family[i].idBuilding = i; 
    }
    return family;
}



class population
{
    private: 
    public:
    std::vector< std::vector <particle> > people;
    int numPeople;
    int numFamilies;
    Shader *pshader;

    population()
    {
        pshader = new Shader("../particle.vs","../particle.fs","../particle.gs");
        srand (time(NULL));
        //scenario s1;
        numFamilies = 500;
        numPeople = 0;
        int numParticles;
        people.resize(numFamilies);
        for(int i=0;i<numFamilies;i++)
        {
            //building mbuilding;
            //buildings.push_back(mbuilding);
            building *mbuilding = new building();
            buildings.push_back(mbuilding);

            int numParticles = rand() % 3 + 1;

            people[i] = randomParticles(mbuilding->mcentrum,numParticles);
            //people[i] = randomParticles(mbuilding.mcentrum,numParticles);
            //people[i] = randomParticles(mbuilding.mcentrum,mbuilding.id);
            
            numPeople += numParticles; 
        }
        std::cout << "1.- Number of Families: " << numFamilies << endl;
        std::cout << "2.- Number of people: " << numPeople << endl; 
        std::cout << "3.- Number of buildings: " << multiple["buildings"].size() << endl;
    }

    void init()
    {
        for(int i=0,z=0;i<people.size();i++)
        {
            for(int j=0;j<people[i].size();j++,z++)
            {
                people[i][j].config();
            }
        }
    }

    void render(const glm::mat4 &view)
    {
        pshader->use();
        for(int i=0,z=0;i<people.size();i++)
        {
            for(int j=0;j<people[i].size();j++,z++)
            {
                people[i][j].render(view,pshader);
            } 
        }
    }

    void done()
    {
        for(int i=0,z=0;i<people.size();i++)
        {
            for(int j=0;j<people[i].size();j++,z++)
            {
                people[i][j].done();
            } 
        }
    }
};


