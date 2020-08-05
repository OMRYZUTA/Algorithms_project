#include "Graph.h"
#pragma warning(disable : 4996)



Graph::Graph()
{
	m_adjMatrix = nullptr;
	m_numOfVertexes = m_numOfEdges = m_sVertex = m_tVertex = 0;
}

Graph::Graph(int i_numOfVertexes = 0, int i_numOfEdges = 0, int i_sVertex = 0, int i_tVertex = 0)  
{
	m_numOfVertexes = i_numOfVertexes;
	m_numOfEdges = i_numOfEdges;
	m_sVertex = i_sVertex;
	m_tVertex = i_tVertex;
	m_adjMatrix = new Edge*[m_numOfVertexes]; // making space for n rows
	for (int row = 0; row < m_numOfVertexes; row++)
	{
		m_adjMatrix[row] = new Edge[m_numOfVertexes]; //making space for n edges 
		
	}
	// the matrix is initiated with Edge default c'tors
}

Graph::Graph(Graph& i_other)
{
	m_numOfVertexes = i_other.m_numOfVertexes;
	m_numOfEdges = i_other.m_numOfEdges;
	m_sVertex = i_other.m_sVertex;
	m_tVertex = i_other.m_tVertex;
	m_adjMatrix = new Edge* [m_numOfVertexes]; // making space for n rows
	for (int row = 0; row < m_numOfVertexes; row++)
	{
		m_adjMatrix[row] = new Edge[m_numOfVertexes]; //making space for n  edges

	}
	for (int i = 0; i < m_numOfVertexes; i++)
		for (int k = 0; k < m_numOfVertexes; k++)
			m_adjMatrix[i][k] = i_other.m_adjMatrix[i][k]; // default opertor '=' will do the work for us
}

Graph::~Graph()
{
	for (int i = 0; i < m_numOfVertexes; i++)
		delete[] m_adjMatrix[i];
	delete m_adjMatrix;
}

void Graph::makeEmptyGraph(int i_numberOfVertexes)
{
	m_numOfVertexes = i_numberOfVertexes;
	m_adjMatrix = new Edge*[i_numberOfVertexes];
	for (int row = 0; row < i_numberOfVertexes; row++)
	{
		m_adjMatrix[row] = new Edge[i_numberOfVertexes];
		// the matrix is initiated with Edge default c'tors
	}
}


bool Graph::isAdjacent(int i_uVertexRow, int i_vVertexColumn)
{
	if (m_adjMatrix[i_uVertexRow][i_vVertexColumn].getEdgeCf() > 0)
		return true;
	else
		return false;
}

List Graph::getAdjListByCapacity(int i_uVertexRow)
{
	List lst;
	for (int i = 0; i < m_numOfVertexes; i++)
	{
		if( m_adjMatrix[i_uVertexRow][i].getEdgeCf()>0)
		lst.addNodeToTail(i);// save in the list all the neighbors of u
	}
	return lst;
}

// also updates the flow and cf
void Graph::addEdgeCapacity(int i_uVertexRow, int i_vVertexColumn, int i_edgeCapacity)
{
	m_adjMatrix[i_uVertexRow][i_vVertexColumn].setEdgeCapacity(i_edgeCapacity);
	m_adjMatrix[i_uVertexRow][i_vVertexColumn].setEdgeFlow(0);
}

void Graph::increaseFlow(int i_uVertex, int i_vVertex, int i_flowToIncrease)
{
	m_adjMatrix[i_uVertex][i_vVertex].setEdgeFlow(m_adjMatrix[i_uVertex][i_vVertex].getEdgeFlow() + i_flowToIncrease);
}

void Graph::removeEdge(int i_uVertexRow, int i_vVertexColumn)
{
	m_adjMatrix[i_uVertexRow][i_vVertexColumn].resetEdge();
}

int Graph::getEdgeCf(int i_uVertex, int i_vVertex)
{

	return m_adjMatrix[i_uVertex][i_vVertex].getEdgeCf();
}

int Graph::getEdgeFlow(int i_uVertex, int i_vVertex)
{
	return m_adjMatrix[i_uVertex][i_vVertex].getEdgeFlow();
}


void Graph::printGraph()
{
	// adding +1 to each edge in order to match the instruction.
	for (int i = 0; i < m_numOfVertexes; i++)
		for (int k = 0; k < m_numOfVertexes; k++)
		{
			if (m_adjMatrix[i][k].getEdgeCf() != 0)
			{
				cout << "Edge (" << i + 1 << "," << k + 1 << ")" << " capacity: "
					<< m_adjMatrix[i][k].getEdgeCapacity() << " flow: "
					<< m_adjMatrix[i][k].getEdgeFlow()<<" cF: "
					<< m_adjMatrix[i][k].getEdgeCf() << endl;

			}
		}
}
int Graph::getNumOfVertexes()
{
	return m_numOfVertexes;
}
int Graph::getSvertex() {
	return m_sVertex;
}

int Graph::getTvertex()
{
	return m_tVertex;
}