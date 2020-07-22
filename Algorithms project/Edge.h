#ifndef __EDGE_H
#define __EDGE_H
#pragma warning (diable: 4996)
#include <iostream>


class Edge
{
private:
     int m_edgeCapacity;
     int m_edgeFlow;
     int m_edgeCf;
public:
     Edge();   //default c'tor
     Edge(int i_edgeCapacity, int i_edgeFlow, int i_edgeCf); //c'tor
     Edge(Edge& i_otherEdge);// copy c'tor
                             // we don't need any move c'tor cause there is no pointers delete later.
     ~Edge();// d'tor
};
#endif