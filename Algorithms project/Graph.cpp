#include "Graph.h"
#pragma warning(disable : 4996)



Graph::Graph()
{
	adjMatrix = nullptr;
	numOfVertex = e = s = t = 0;
}

Graph::Graph(int numOfVertex = 0, int e = 0, int s = 0, int t = 0)  
{
	this->numOfVertex = numOfVertex;
	this->e = e;
	this->s = s;
	this->t = t;
	adjMatrix = new int*[numOfVertex]; // making space for n rows
	for (int row = 0; row < numOfVertex; row++)
	{
		adjMatrix[row] = new int[numOfVertex]; //making space for n ints/ edges delete later
		for (int column = 0; column < numOfVertex; column++)
		{
			adjMatrix[row][column] = 0;// initing
		}
	}
}

Graph::Graph(Graph& other)
{
	this->numOfVertex = other.numOfVertex;
	this->e = other.e;
	this->s = other.s;
	this->t = other.t;
	adjMatrix = new int* [this->numOfVertex]; // making space for n rows
	for (int row = 0; row < numOfVertex; row++)
	{
		adjMatrix[row] = new int[numOfVertex]; //making space for n ints/ edges delete later

	}
	for (int i = 0; i < numOfVertex; i++)
		for (int k = 0; k < numOfVertex; k++)
			adjMatrix[i][k] = other.adjMatrix[i][k];
}

Graph::~Graph()
{
	for (int i = 0; i < numOfVertex; i++)
		delete adjMatrix[i];
	delete adjMatrix;
}

void Graph::makeEmptyGraph(int n)
{
	this->numOfVertex = n;
	adjMatrix = new int*[n];
	for (int row = 0; row < n; row++)
	{
		adjMatrix[row] = new int[n];
		for (int column = 0; column < n; column++)
		{
			adjMatrix[row][column] = 0;
		}
	}
}


bool Graph::isAdjacent(int u, int v)//
{
	if (adjMatrix[u][v] > 0)
		return true;
	else
		return false;
}

List Graph::getAdjList(int u)
{
	List lst;
	for (int i = 0; i < numOfVertex; i++)
	{
		if( adjMatrix[u][i]>0)
		lst.addNodeToTail(i);// save in the list all the neighbors of u
	}
	return lst;
}

void Graph::addEdge(int u, int v, int c)
{
	adjMatrix[u][v] = c;
}

void Graph::removeEdge(int u, int v)
{
	adjMatrix[u][v] = 0;
}


void Graph::printGraph()
{
	// adding +1 to each edge in order to match the instruction.
	for (int i = 0; i < numOfVertex; i++)
		for (int k = 0; k < numOfVertex; k++)
		{
			if(adjMatrix[i][k]!= 0)
			cout << "Edge (" << i + 1 << "," << k + 1 << ")" << " capacity: "
				<< adjMatrix[i][k] << endl;
		}
}
int Graph::getNumOfVertexes()
{
	return numOfVertex;
}
int Graph::getSvertex() {
	return s;
}

int Graph::getTvertex()
{
	return t;
}