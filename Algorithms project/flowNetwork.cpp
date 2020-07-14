#include "flowNetwork.h"
#include "Queue.h"
#pragma warning(disable : 4996)

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
          while (!q.isEmpty())
          {
               u = q.dequeue(); // handling this vertex now
               List ls= g.getAdjList(u);// get adjecency list
               Node* tempNode = ls.getHead(); //in order to go through the list
               while (tempNode)
               {
                    if (dArr[tempNode->getData()] == -1) // -1= infinity
                    {
                         dArr[tempNode->getData()] = dArr[u] + 1;// d[v]=d[u]+1
                         pArr[tempNode->getData()] = u;
                         q.enqueue(tempNode->getData());//q.Enqueue(v)
                         
                    }
               }
          }
          List track; //builiding the track from parents array
          track.addNodeToHead(g.getTvertex());// adding t to be eventually the tail
          int tempParent = pArr[g.getTvertex()]; 
          while (pArr[tempParent]!=-1)
          {
               track.addNodeToHead(pArr[tempParent]);
               tempParent = pArr[tempParent];
          }
          track.addNodeToHead(g.getSvertex()); // because when we get to s we break the loop
          return track;
}