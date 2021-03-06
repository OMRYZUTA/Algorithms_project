#ifndef __EDGE_H
#define __EDGE_H
#pragma warning (diable: 4996)
#include <iostream>

using namespace std;

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
                             // we don't need any move c'tor cause there are no pointers 

//setters:
     void setEdgeCapacity(int i_edgeCapacity);
     void setEdgeFlow(int i_edgeFlow);// also updates cf
 
     int getEdgeCf();
     int getEdgeFlow();      // getters
     int getEdgeCapacity();

     void resetEdge(); // make flow capacity and cf equal to zero
     
     virtual  ~Edge();// d'tor
};
#endif