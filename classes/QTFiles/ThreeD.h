#ifndef THREED_H
#define THREED_H
#include <vector>
#include "edge.h"
class ThreeD{
    public:
       std::vector<Edge *> edge_list;
    public:
       ThreeD(std::vector<Edge *> edgeList);

};

#endif
