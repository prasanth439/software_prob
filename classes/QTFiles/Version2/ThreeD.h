#ifndef THREED_H
#define THREED_H
#include <vector>
#include "edge.h"
class ThreeD{
    public:
       std::vector<Edge *> edge_list_pers;
       std::vector<Edge *> edge_list_top;
       std::vector<Edge *> edge_list_side;
       std::vector<Edge *> edge_list_front;
       std::vector<Vertex *> vertex_list_pers;
       std::vector<Vertex *> vertex_list_top;
       std::vector<Vertex *> vertex_list_side;
       std::vector<Vertex *> vertex_list_front;
       int list_number;


    public:
       ThreeD(std::vector<Edge *> edgeList_perspective);
       void from_threed_file();
       void from_twod_file();

};

#endif
