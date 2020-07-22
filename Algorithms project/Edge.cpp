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



Edge::~Edge() // there is nothing to delete right now
{
}
