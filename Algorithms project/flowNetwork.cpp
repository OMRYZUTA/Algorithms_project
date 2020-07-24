#include "flowNetwork.h"
#include "Queue.h"
#pragma warning(disable : 4996)

FlowNetwork::FlowNetwork():m_graph(),m_minCut()
{
     m_maxFlow  = m_currentFlow=0;
}

FlowNetwork::FlowNetwork(Graph i_graph, int i_maxflow, int i_currentflow):m_graph(i_graph),m_minCut()
{
     m_maxFlow = i_maxflow;
     m_currentFlow = i_currentflow;
}

FlowNetwork::FlowNetwork(FlowNetwork& i_otherFlowNetwork):m_graph(i_otherFlowNetwork.m_graph),m_minCut(i_otherFlowNetwork.m_minCut)
{
    m_maxFlow = i_otherFlowNetwork.m_maxFlow;
    m_currentFlow =i_otherFlowNetwork.m_currentFlow;
}

FlowNetwork::~FlowNetwork()
{
	
}

int* FlowNetwork::BFS()
{
     Queue q;
     int arrSize = m_graph.getNumOfVertexes();
     int* dArr = new int[arrSize];
     int* pArr = new int[arrSize];
          for (int i = 0; i < arrSize; i++)
          {
               dArr[i] = INFINITY_val;  // init the arr. -1 = infinty
               pArr[i] = NO_parent; // to indicate that there is no parent
          }
          q.enqueue(m_graph.getSvertex());
          dArr[m_graph.getSvertex()] = 0;
          int u;// temp vertex, inspired by page 98 in the book
          int v;
          while (!q.isEmpty())
          {
               u = q.dequeue(); // handling this vertex now
               List ls= m_graph.getAdjListByCapacity(u);// get adjacency list
               Node* tempNode = ls.getHead(); //in order to go through the list
               while (tempNode)
               {
                    v = tempNode->getData();
                    if (dArr[v] == INFINITY_val) // -1= infinity
                    {
                         dArr[v] = dArr[u] + 1;// d[v]=d[u]+1
                         pArr[v] = u;
                         q.enqueue(v);//q.Enqueue(v)
                         
                    }
                    tempNode = tempNode->getNext();
               }
          }
          delete[]dArr;
          return pArr;
}

List FlowNetwork::findRouteFromStoT(int* i_pArr)
{
     if (i_pArr == nullptr)
     {
          cout << "Error pArr is nullptr";
          exit(1);
     }

   
     List routeFromStoT; //building the track from parents array
     routeFromStoT.addNodeToHead(m_graph.getTvertex());// adding t to be eventually the tail
     int tempParent = i_pArr[m_graph.getTvertex()];
     while (tempParent != NO_parent)
     {
          routeFromStoT.addNodeToHead(tempParent);
          tempParent = i_pArr[tempParent];
     }
     // return List that represent path of vertexes from s to t 
     if (routeFromStoT.getHead()->getData() != m_graph.getSvertex())
     {
          routeFromStoT.makeEmpty();
     }
     delete[] i_pArr;
     return routeFromStoT;
}
