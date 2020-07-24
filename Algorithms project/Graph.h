#ifndef __GRAPH_H
#define __GRAPH_H

#include "Cut.h"
#include "Node.h"
#include "List.h"
#include "Edge.h"

class Graph
{
private:
	Edge** m_adjMatrix; 
	int m_numOfVertexes, m_numOfEdges, m_sVertex, m_tVertex;

public:
	Graph();             // deafult c'tor
	Graph(int i_numOfVertexes, int i_numOfEdges ,int i_sVertex, int i_tVertex);         // c'tor with arguments
	Graph(Graph& other);        // copy c'tor
	~Graph();      // d'tor 
	void makeEmptyGraph(int i_numOfVertexes);

	bool isAdjacent(int i_uVertex, int i_vVertex);
	List getAdjListByCapacity(int i_uVertex);

	void addEdgeCapacity(int i_uVertexRow, int i_vVertexColumn, int i_edgeCapacity);
	
	void increaseFlow(int i_uVertex, int i_vVertex, int i_flowToIncrease);
	void removeEdge(int i_uVertex, int i_vVertex);
	int getEdgeCf(int i_uVertex, int i_vVertex);
	void printGraph();

	int getNumOfVertexes();
	int getSvertex();
	int getTvertex();

};
#endif // __GRAPH_H
