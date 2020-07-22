#ifndef __GRAPH_H
#define __GRAPH_H

#include "Cut.h"
#include "Node.h"
#include "List.h"
#include "Edge.h"

class Graph
{
private:
	int** adjMatrix; 
	int numOfVertex, e, s, t;  // n - numofvertex, e - numofedges             

public:
	Graph();             // deafult c'tor
	Graph(int n, int e ,int s, int t);         // c'tor with arguments
	Graph(Graph& other);        // copy c'tor
	~Graph();      // d'tor 
	void makeEmptyGraph(int n);
	bool isAdjacent(int u, int v);
	List getAdjList(int u);
	void addEdge(int u, int v, int c);
	void removeEdge(int u, int v);
	void printGraph();
	int getNumOfVertexes();
	int getSvertex();
	int getTvertex();

};
#endif // __GRAPH_H
