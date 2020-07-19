#include "flowNetwork.h"
#include "Queue.h"
#pragma warning(disable : 4996)

FlowNetwork::FlowNetwork():g(),mincut()
{
     maxFlow  = currFlow=0;
}

FlowNetwork::FlowNetwork(Graph g, int maxflow, int currflow):g(g),mincut()
{
     this->maxFlow = maxflow;
     this->currFlow = currflow;
}

FlowNetwork::FlowNetwork(FlowNetwork& other):g(other.g),mincut(other.mincut)
{
     this->maxFlow = other.maxFlow;
     this->currFlow =other.currFlow;
}

FlowNetwork::~FlowNetwork()
{
	//aaaaa
}

List FlowNetwork::BFS()
{
     Queue q;
     int arrSize = g.getNumOfVertexes();
     int* dArr = new int[arrSize];
     int* pArr = new int[arrSize];
          for (int i = 0; i < arrSize; i++)
          {
               dArr[i] = -1;  // init the arr. -1 = infinty
               pArr[i] = -1; // to indicate that there is no parent
          }
          q.enqueue(g.getSvertex());
          dArr[g.getSvertex()] = 0;
          int u;// temp vertex, inpired by page 98 in the book
          int v;
          while (!q.isEmpty())
          {
               u = q.dequeue(); // handling this vertex now
               List ls= g.getAdjList(u);// get adjacency list
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
          track.addNodeToHead(g.getTvertex());// adding t to be eventually the tail
          int tempParent = pArr[g.getTvertex()]; 
          while (tempParent!=-1)
          {
               track.addNodeToHead(tempParent);
               tempParent = pArr[tempParent];
          }
         
          return track;
}