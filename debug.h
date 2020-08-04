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

float angle(glm::vec3 a, glm::vec3 b)
{
    float theta = atan2(b.y-a.y,b.x-a.x);
    return theta;
}
bool cmpx(glm::vec3 a, glm::vec3 b)
{
    return a.x < b.x;
}

// Triangulos con vertices en comun - pertenecen a un mismo bloque
// convex hull
// puntos mas cercans 2 , 3 cada uno reemplazar por un solo punto medio.
// create a graph 
// floyd warshall -> all shortest path 
// define a time series for get food
// move people to shopping center (after to choose the shopping buldings)
// texture para el color yla fuente.

std::vector<glm::vec3> createRoadMap()
{
    //std::vector< std::vector<glm::vec3> > nodes;
    int numBuildings = multiple["buildings"].size();
    //nodes.resize(numSquares); 
    vector<glm::vec3> contour;
    for(int i=0;i<numBuildings;i++)
    {
        float ansx=10;
        float ansy=10;
        vector<glm::vec3> m = multiple["buildings"][i];
        glm::vec3 minx = glm::vec3(1.0f,0.5f,0.0f);
        for(int j=0;j<multiple["buildings"][i].size();j++)
        {
            if(cmpx(multiple["buildings"][i][j],minx))
            {
                minx = multiple["buildings"][i][j];
            }          
            // here
        }
        contour.push_back(minx);
    }
    std::cout << "countouor: " << contour.size() << std::endl;
    
    return contour;
}

bool cmp(building* a,building* b)
{
    //cout << a->id << "," << b->id << endl;
    for(int i=0;i<a->vertices.size();i++)
    {
        for(int j=0;j<b->vertices.size();j++)
        {
            if(a->vertices[i] == b->vertices[j])
                return true;
        }
    }
    return false;
}

void union2(building* a, building* b)
{
    if( a->id != b->id)
    {
        building* it = a;
        while(it->parent!=NULL) it = it->parent;
        building* root_a = it;
        it = b;
        while(it->parent!=NULL) it = it->parent;
        building* root_b = it;
        //cout << "root_b->parent: " << root_b->parent << " root_a: " << root_a << endl;
        root_b->parent = root_a;
        root_b->id = root_a->id;
        for(int i=0;i<buildings.size();i++)
        {
            if(buildings[i]->parent == root_b)
            {
                buildings[i]->parent = root_a; 
                buildings[i]->id = root_a->id;
            }
        }
    }
}

std::vector<glm::vec3> findBuildings()
{
    std::vector<glm::vec3> ver;
    for(int i=0;i<buildings.size();i++)
    {
        for(int j=i+1;j<buildings.size();j++)
        {
            if( cmp(buildings[i],buildings[j]) )
            {
                union2(buildings[i],buildings[j]);
            }
        }
    }    

    for(int i=0;i<buildings.size();i++)
    {

        //buildings[i]->parent->id

        
        if(buildings[i]->parent == buildings[16] or buildings[i] == buildings[16])
        {
            for(int j=0;j<buildings[i]->vertices.size();j++)
            {
                ver.push_back(buildings[i]->vertices[j]);
            }
        }
        
    }

    
    return ver;

}


vector<glm::vec3> getRoad()
{
    return singular["roads"];
}

class debug
{
    public:
    unsigned int vao;
    unsigned int vbo;
    vector<glm::vec3> points;
    float radius;
    Shader *pshader;
    debug(){
        //mtarget = HOME;
        pshader = new Shader("../debug.vs","../debug.fs","../debug.gs");
        this->radius = 0.002;
        //points = createRoadMap();
        //points = getRoad();
        //points = findPoints();

        /*
        for(int i=0;i<buildings.size();i++)
        {
            for(int j=i+1;j<buildings.size();j++)
            {
                cout << "i: " << i << "," << "j: " << j << " - b i id: "<< buildings[i]->id << "," <<  buildings[j]->id << endl; 
            }
        }*/

        points = findBuildings();
        /*
        for(int i=0;i<points.size();i++)
        {
            std::cout << points[i].x << "," << points[i].y << "," << points[i].z << std::endl;
        }
        */
    }

    void init()
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData( GL_ARRAY_BUFFER, points.size()*sizeof(glm::vec3), glm::value_ptr(points[0]), GL_STATIC_DRAW );
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        glBindVertexArray(0);
    }

    void render(const glm::mat4 &view)
    {    
        pshader->use();    
        glBindVertexArray(vao);
        glm::mat4 model = glm::mat4(1.0f);
        pshader->setMat4("model", model);
        pshader->setMat4("view", view);
        pshader->setFloat("u_cRadius",this->radius);
        glDrawArrays( GL_POINTS, 0, points.size() );
        glBindVertexArray(0);     
    }

    void done()
    {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
    }
};