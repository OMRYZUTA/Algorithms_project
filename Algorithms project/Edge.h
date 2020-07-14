#ifndef __EDGE_H
#define __EDGE_H
#pragma warning (diable: 4996)
#include <iostream>


class Edge
{
private:
     int capacity;
     int flow;
     int cf;
public:
     Edge();
     Edge(int capacity, int flow, int cf);
     Edge(Edge& other);
     ~Edge();
};
#endif