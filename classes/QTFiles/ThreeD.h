#ifndef THREED_H
#define THREED_H
#include <vector>
#include <string>
#include "edge.h"
class ThreeD{
    public:
       std::vector<Edge *> edge_list_pers;
       //std::vector<Edge *> edge_list_top;
       //std::vector<Edge *> edge_list_side;
       //std::vector<Edge *> edge_list_front;
       std::vector<Vertex *> vertex_list_pers;
       //std::vector<Vertex *> vertex_list_top;
       //std::vector<Vertex *> vertex_list_side;
       //std::vector<Vertex *> vertex_list_front;
       bool ready;


    public:
       ThreeD();
       void from_threed_file(std::string str);
       void from_twod_file(std::string str1,std::string str2,std::string str3);

};

#endif
