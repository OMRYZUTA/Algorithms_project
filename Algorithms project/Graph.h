#ifndef __GRAPH_H
#define __GRAPH_H
#include "Node.h"
#include "List.h"

class Graph
{
private:
	int** adjMatrix; 
	int n, e, s, t;  // n - numofvertex, e - numofedges             

public:
	Graph();                     // c'tor
	Graph(int n, int e ,int s, int t);         // c'tor
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
