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
using namespace std;
map< std::string,std::vector<glm::vec3> > singular; // line, polygon
map< std::string,std::vector<vector<glm::vec3> > > multiple; // multipolygons, multilines   , Define as Elements 

class building;
vector<building*> buildings;
#define PI 3.1415