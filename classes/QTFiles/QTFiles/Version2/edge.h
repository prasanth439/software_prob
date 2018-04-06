#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"

class Edge{
    public:
        Vertex *p,*q;
    public:
        Edge(Vertex *p,Vertex* q);

};
#endif // EDGE_H
