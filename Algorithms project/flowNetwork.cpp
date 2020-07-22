#include "flowNetwork.h"
#include "Queue.h"
#pragma warning(disable : 4996)

FlowNetwork::FlowNetwork():m_graph(),m_minCut()
{
     m_maxFlow  = m_currentFlow=0;
}

FlowNetwork::FlowNetwork(Graph i_graph, int i_maxflow, int i_currentflow):m_graph(i_graph),m_minCut()
{
     this->m_maxFlow = i_maxflow;
     this->m_currentFlow = i_currentflow;
}

FlowNetwork::FlowNetwork(FlowNetwork& i_otherFlowNetwork):m_graph(i_otherFlowNetwork.m_graph),m_minCut(i_otherFlowNetwork.m_minCut)
{
     this->m_maxFlow = i_otherFlowNetwork.m_maxFlow;
     this->m_currentFlow =i_otherFlowNetwork.m_currentFlow;
}

FlowNetwork::~FlowNetwork()
{
	
}

void FlowNetwork::BFS()
{
     Queue q;
     int arrSize = m_graph.getNumOfVertexes();
     int* dArr = new int[arrSize];
     int* pArr = new int[arrSize];
          for (int i = 0; i < arrSize; i++)
          {
               dArr[i] = -1;  // init the arr. -1 = infinty
               pArr[i] = -1; // to indicate that there is no parent
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
                    if (dArr[v] == -1) // -1= infinity
                    {
                         dArr[v] = dArr[u] + 1;// d[v]=d[u]+1
                         pArr[v] = u;
                         q.enqueue(v);//q.Enqueue(v)
                         
                    }
                    tempNode = tempNode->getNext();
               }
          }
          List track; //building the track from parents array
          track.addNodeToHead(m_graph.getTvertex());// adding t to be eventually the tail
          int tempParent = pArr[m_graph.getTvertex()]; 
          while (tempParent!=-1)
          {
               track.addNodeToHead(tempParent);
               tempParent = pArr[tempParent];
          }
         // return path from s 
        //  return track;
}