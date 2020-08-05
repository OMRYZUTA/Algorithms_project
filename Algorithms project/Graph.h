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
	Graph();             // default c'tor
	Graph(int i_numOfVertexes, int i_numOfEdges ,int i_sVertex, int i_tVertex);         // c'tor with arguments
	Graph(Graph& i_other);        // copy c'tor
	virtual ~Graph();      // d'tor 
	void makeEmptyGraph(int i_numOfVertexes);

	bool isAdjacent(int i_uVertex, int i_vVertex);// return the answer if 2 vertexes are neighbors 
	List getAdjListByCapacity(int i_uVertex);// return list of neighbors

	void addEdgeCapacity(int i_uVertexRow, int i_vVertexColumn, int i_edgeCapacity);// adding the capacity in the new edge (u,v)
	
	void increaseFlow(int i_uVertex, int i_vVertex, int i_flowToIncrease);// increase flow in the edge (u,v)
	void removeEdge(int i_uVertex, int i_vVertex); 
	int getEdgeCf(int i_uVertex, int i_vVertex);
	int getEdgeFlow(int i_uVertex, int i_vVertex);
	void printGraph();

	int getNumOfVertexes();
	int getSvertex();
	int getTvertex();

};
#endif // __GRAPH_H
