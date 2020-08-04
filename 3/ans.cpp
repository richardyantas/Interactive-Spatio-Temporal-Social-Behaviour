
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

using namespace std;
using json = nlohmann::json;
namespace pt = boost::property_tree;


const unsigned int SCR_WIDTH_C = 1000;
const unsigned int SCR_HEIGHT_C = 600;

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

map<string,std::vector<glm::vec3>> singular; // line, polygon
map<string,std::vector<vector<glm::vec3>>> multiple; // multipolygons, multilines   , Define as Elements 

vector<feature> features;
void readJson();

class city
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

    city(float x = 0.0f, float y = 0.0f, float z = 0.0f, float radius = 100.0f)
    {
        readJson();   
        string type = "water";
        for(int i=0;i<singular[type].size();i++)
        {
          vertices.push_back(singular[type][i]);
        }
        type = "earth";
        for(int i=0;i<singular[type].size();i++)
        {
          vertices.push_back(singular[type][i]);
        }
        vertices.push_back(glm::vec3(0,0,0));

        pshader = new Shader("../city.vs","../city.fs");
        //pshader = new Shader("../particle.vs","../particle.fs");
        center = glm::vec3(( 1. / SCR_WIDTH_C )*x,( 1. / SCR_HEIGHT_C )*y, 0.0f );   // Transform from world to gl
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
        model = glm::scale( model, glm::vec3( 1.0f, 1.0f, 1.0f ) );
        model = glm::translate(model, move ); //?? delta or the end
        //float angle = 20.0f ;
        //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.1f));
        pshader->setMat4("model", model);
        pshader->setMat4("view", view);
        //glDrawElements(GL_LINE_STRIP, (GLsizei)indices.size()*3, GL_UNSIGNED_INT, NULL);    
        //glDrawArrays( GL_POINTS, 0, vertices.size() );
        //glDrawArrays(GL_TRIANGLES, 0, 36);
        glDrawArrays(GL_LINE_STRIP, 0, vertices.size()-12 );
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





void readJson()
{
  //GLuint id = glCreateShader( GL_VERTEX_SHADER );
  /*
  pt::ptree root;
  pt::read_json("../file.json", root);  // Load the json file in this ptree
  int roll = root.get<int>("roll no");  //read and save the roll no in *roll*
  string  name = root.get<string>("name");  //read and save the name in *name*
  string class1 = root.get<string>("class");  //read and save the class in *class1*
  cout << "name : " << name << endl;      //getting the output of all
  cout << "roll no : " << roll << endl;
  cout << "class : " << class1 << endl << "address : " << endl << endl;
  for (pt::ptree::value_type & v : root.get_child("address"))
  {
    cout << v.first << endl;
    cout << "  "<<v.second.data() << endl;
  }
  */
  ifstream ifs("../Evergate1.json");
  json f = json::parse(ifs);
  int n = f["features"].size();
  features.resize(n);

  string list[9] = { "earth", "rivers", "roads", "walls", "buildings", "squares", "greens", "fields", "water"};

  float r =  f["features"][1]["geometry"]["coordinates"][0][0][0];//f["features"][0]["properties"]["roadWidth"];
  std::cout << "n: " << n << std::endl;
  
  /*
  for(int i=1;i<2;i++) // i<n
  {
    for(int t=0;t<8;t++)
    {
      if(f["features"][i]["properties"]["id"]==list[t])
      {
        int s = f["features"][i]["geometry"]["coordinates"][0].size();
        features[i-1].id = list[t];
        for(int j=0;j<s;j++)
        {
          float x = f["features"][i]["geometry"]["coordinates"][0][j][0];
          float y = f["features"][i]["geometry"]["coordinates"][0][j][1];
          std::cout << "pair: "  << 100*x << " " << 100*y << std::endl;
          features[i-1].coordinates.push_back( glm::vec3(100*x,100*y,0) );
        }
      }
    }
  }
  */

  
  for(int i=1;i<10;i++) // i<n
  {
    int s = f["features"][i]["geometry"]["coordinates"][0].size();
    string id = f["features"][i]["properties"]["id"];
    string type = f["features"][i]["geometry"]["type"];
    if ( type == "Polygon" or type == "MultiLineString" )
    {
      
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
      
      for(int j=0;j<s;j++)
      {
        std::vector<glm::vec3> subset;
        int  nsubset = f["features"][i]["geometry"]["coordinates"][0][j].size();
        for(int u=0;u<nsubset;u++)
        {
          float x = f["features"][i]["geometry"]["coordinates"][0][j][u][0];
          float y = f["features"][i]["geometry"]["coordinates"][0][j][u][1];
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

