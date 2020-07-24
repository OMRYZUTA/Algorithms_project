#include "Edge.h"
#pragma warning(disable : 4996)

Edge::Edge()
{
     m_edgeCapacity = 0;
     m_edgeFlow = 0;
     m_edgeCf = 0;
}

Edge::Edge(int i_edgeCapacity, int i_edgeFlow, int i_edgeCf)
{
     m_edgeCapacity = i_edgeCapacity;
     m_edgeFlow = i_edgeFlow;
     m_edgeCf = i_edgeCf;
}

Edge::Edge(Edge& other)
{
     m_edgeCapacity = other.m_edgeCapacity;
     m_edgeFlow = other.m_edgeFlow;
     m_edgeCf = other.m_edgeCf;
}

void Edge::setEdgeCapacity(int i_edgeCapacity)
{
     m_edgeCapacity =  i_edgeCapacity;
}

void Edge::setEdgeFlow(int i_edgeFlow)
{
     if (i_edgeFlow > m_edgeCapacity)
     {
          cout << "Error! impossible to set this Flow ";
          exit(1);
     }
     m_edgeFlow = i_edgeFlow;
     m_edgeCf = m_edgeCapacity - m_edgeFlow;
}

int Edge::getEdgeCf()
{
     return m_edgeCf;
}

int Edge::getEdgeFlow()
{
     return m_edgeFlow;
}

int Edge::getEdgeCapacity()
{
     return m_edgeCapacity;
}

void Edge::resetEdge()
{
     m_edgeCapacity = 0;
     m_edgeCf = 0;
     m_edgeFlow = 0;
}



Edge::~Edge() // there is nothing to delete right now
{
}
