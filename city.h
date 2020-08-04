#pragma once

#include <string.h>
#include <exception>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <nlohmann/json.hpp>
#include <shader.h>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp> 
//#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include "glm/gtx/string_cast.hpp"
//#include "glm/ext.hpp"
#include "common.h"

using namespace std;
using json = nlohmann::json;
namespace pt = boost::property_tree;
const unsigned int SCR_WIDTH_C = 1000;
const unsigned int SCR_HEIGHT_C = 600;
class feature;
vector<feature> features;
void readJson();

class feature
{
  public:
  string id;
  std::vector< glm::vec3 > coordinates; // vertices
  feature(){}
  feature(string id,const std::vector< glm::vec3 > &coordinates )
  {
    this->id = id;
    this->coordinates = coordinates;
  }
};


class city
{
    private:

    vector<unsigned int> vaos;
    vector<unsigned int> vbos;
    std::vector< vector<glm::vec3> > setVertices;
    std::vector<glm::vec3> vertices;
    unsigned int VAO;
    unsigned int VBO;
    Shader *pshader;
    float radius;
    glm::vec3 center;
    glm::vec3 target;
    glm::vec3 move;

    public:

    city(float x = 0.0f, float y = 0.0f, float z = 0.0f, float radius = 100.0f)
    {
        readJson();   
        setVertices.push_back(singular["water"]);
        setVertices.push_back(singular["earth"]);
        setVertices.push_back(singular["roads"]);
        setVertices.push_back(singular["rivers"]);

        std::cout << "mm: " <<multiple["buildings"].size() << endl;
        for (int i = 0; i < multiple["buildings"].size() ; i++)
          setVertices.push_back(multiple["buildings"][i]);
        //  string list[9] = { , "rivers", "roads",     "walls",,     "squares", "greens", "fields", };
        for (int i = 0; i < multiple["walls"].size() ; i++)
          setVertices.push_back(multiple["walls"][i]);
        //for (int i = 0; i < multiple["greens"].size() ; i++)
        //  setVertices.push_back(multiple["greens"][i]);
        for (int i = 0; i < multiple["fields"].size() ; i++)
          setVertices.push_back(multiple["fields"][i]);
        /*
        for (int i = 0; i < multiple["buildings"].size() ; i++)
        {
          for(int j=0;j<multiple["buildings"][i].size();j++)
            std::cout << multiple["buildings"][i][j][0] << ",";
          std::cout << std::endl;
        }
        */
        

        pshader = new Shader("../city.vs","../city.fs");
    }

    void init()
    {
        int n = setVertices.size();
        //std::cout << "3.- number of Buildings: " << n << endl;
        vaos.resize(n);
        vbos.resize(n);
        for(int i=0;i<vaos.size();i++) // The same size of vbos
        {
          glGenVertexArrays(1, &vaos[i]);
          glBindVertexArray(vaos[i]);
          glGenBuffers(1, &vbos[i]);
          glBindBuffer(GL_ARRAY_BUFFER, vbos[i]);
          //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
          glBufferData( GL_ARRAY_BUFFER, setVertices[i].size()*sizeof(glm::vec3), glm::value_ptr( setVertices[i][0]), GL_STATIC_DRAW );
          //glBufferData( GL_ARRAY_BUFFER, indices.size()*sizeof(glm::uvec3), glm::value_ptr(indices[0]), GL_STATIC_DRAW );
          // position attribute
          //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);  // The first 0 indicate the location = 0 in vertex shader, if you texture coords 5 * sizeof
          glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
          glEnableVertexAttribArray(0);
          glBindBuffer(GL_ARRAY_BUFFER, 0); 
          glBindVertexArray(0);
        }
    }

    void render(const glm::mat4 &view)
    {
        pshader->use();
        for(int i=0;i<vaos.size();i++)
        {
          glBindVertexArray(vaos[i]);
          glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
          //model = glm::scale( model, glm::vec3( 1.0f, 1.0f, 1.0f ) );
          //model = glm::translate(model, move ); //?? delta or the end
          pshader->setMat4("model", model);
          pshader->setMat4("view", view);
          if(i==2 or i==3)
            glDrawArrays(GL_LINE_STRIP, 0, setVertices[i].size() );
          else
            glDrawArrays(GL_LINE_LOOP, 0, setVertices[i].size() );

          glBindVertexArray(0);
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

void readJson()
{
  ifstream ifs("../Fingdone.json");
  //ifstream ifs("../OtterThicket.json");
  json f = json::parse(ifs);
  int n = f["features"].size();
  features.resize(n);

  string list[9] = { "earth", "rivers", "roads", "walls", "buildings", "squares", "greens", "fields", "water"};

  float r =  f["features"][1]["geometry"]["coordinates"][0][0][0];//f["features"][0]["properties"]["roadWidth"];
  std::cout << "n: " << n << std::endl;

  for(int i=1;i<n;i++) // i<n
  {  
    string id = f["features"][i]["properties"]["id"];
    string type = f["features"][i]["geometry"]["type"];
    if ( type == "Polygon" or type == "MultiLineString" )
    {
      int s = f["features"][i]["geometry"]["coordinates"][0].size();
      for(int j=0;j<s;j++)
      {
        float x = f["features"][i]["geometry"]["coordinates"][0][j][0];
        float y = f["features"][i]["geometry"]["coordinates"][0][j][1];
        singular[id].push_back( glm::vec3(100*x,100*y,0.0));
      }
      std::cout << id << std::endl;
    }
    else
    {
      int s = f["features"][i]["geometry"]["coordinates"].size();
      for(int j=0;j<s;j++)
      {
        std::vector<glm::vec3> subset;
        int  nsubset = f["features"][i]["geometry"]["coordinates"][j][0].size();
        for(int u=0;u<nsubset;u++)
        {
          float x = f["features"][i]["geometry"]["coordinates"][j][0][u][0];
          float y = f["features"][i]["geometry"]["coordinates"][j][0][u][1];
          subset.push_back(glm::vec3(100*x,100*y,0.0));
        }
        multiple[id].push_back( subset);
        subset.clear();
      }
      std::cout << id << std::endl;
    } 
  }
  std::cout << ":)" << std::endl;
  return;
}

