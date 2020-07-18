#include "Edge.h"
#pragma warning(disable : 4996)

Edge::Edge()
{
     capacity = 0;
     flow = 0;
     cf = 0;
}

Edge::Edge(int capacity, int flow, int cf)
{
     this->capacity = capacity;
     this->flow = flow;
     this->cf = cf;
}

Edge::Edge(Edge& other)
{
     capacity = other.capacity;
     flow = other.flow;
     cf = other.cf;
}

Edge::~Edge()
{
}
