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

int* FlowNetwork::BFS(int *i_dArr)
{
     Queue q;
     int arrSize = m_graph.getNumOfVertexes();
    
     int* pArr = new int[arrSize];
          for (int i = 0; i < arrSize; i++)
          {
               i_dArr[i] = INFINITY_val;  // init the arr. -1 = infinty
               pArr[i] = NO_parent; // to indicate that there is no parent
          }
          q.enqueue(m_graph.getSvertex());
          i_dArr[m_graph.getSvertex()] = 0;
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
                    if (i_dArr[v] == INFINITY_val) // -1= infinity
                    {
                         i_dArr[v] = i_dArr[u] + 1;// d[v]=d[u]+1
                         pArr[v] = u;
                         q.enqueue(v);//q.Enqueue(v)
                         
                    }
                    tempNode = tempNode->getNext();
               }
          }
        
          return pArr;
}

int FlowNetwork::findMinCfInRoute(List i_trackFromStoT)
{
     int minCf;
     Node* tempVertexU, * tempVertexV;
     
     tempVertexU = i_trackFromStoT.getHead();
     if (tempVertexU)
     {
          tempVertexV = tempVertexU->getNext();
          if (tempVertexV)
          {
               minCf = m_graph.getEdgeCf(tempVertexU->getData(), tempVertexV->getData());
          }
          else
          {
               cout << "Error! there is no Edge in route";
               exit(1);
          }
     }
     else
     {
          cout << "Error! there is no Edge in route";
          exit(1);
     }
     while (tempVertexV)
     {
         
          if (tempVertexV)
          {
               if(minCf > m_graph.getEdgeCf(tempVertexU->getData(), tempVertexV->getData()))
               {
                    minCf = m_graph.getEdgeCf(tempVertexU->getData(), tempVertexV->getData());
               }
          }
          tempVertexU = tempVertexV;
          tempVertexV = tempVertexV->getNext();
     }
     return minCf;

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

void FlowNetwork::increaseFlow(List i_trackFromStoT, int i_flowToIncrease)
{
   
     Node* tempVertexU, * tempVertexV;

     tempVertexU = i_trackFromStoT.getHead();
     if (tempVertexU)
     {
          tempVertexV = tempVertexU->getNext(); // need to change this delete later. make it readable
          if (!tempVertexV)
          {
               cout << "Error! there is no Edge in route";
               exit(1);
          }
       
     }
     else
     {
          cout << "Error! there is no Edge in route";
          exit(1);
     }
     m_currentFlow += i_flowToIncrease;// updating currentFlow

     while (tempVertexV)
     {
          // increase flow by i_flowToIncrease
          
          m_graph.increaseFlow(tempVertexU->getData(), tempVertexV->getData(), i_flowToIncrease);
          //decrease flow by i_flowToIncrease in the opposite edge
          m_graph.increaseFlow(tempVertexV->getData(), tempVertexU->getData(), -i_flowToIncrease);
          
          tempVertexU = tempVertexV;
          tempVertexV = tempVertexV->getNext();
     }
}

int FlowNetwork::fordFulkersonMethodWithBFS()
{
     int arrSize = m_graph.getNumOfVertexes();
     int* dArr = new int[arrSize];
     int* tempParentsArray = nullptr;
     tempParentsArray = BFS(dArr);
     List tempRouteFromStoT = findRouteFromStoT(tempParentsArray);
     int tempMinCf = 0;
     while (!tempRouteFromStoT.isEmpty())
     {
          tempMinCf = findMinCfInRoute(tempRouteFromStoT);
          increaseFlow(tempRouteFromStoT, tempMinCf);
          tempParentsArray = BFS(dArr);
          tempRouteFromStoT = findRouteFromStoT(tempParentsArray); //move operator =
          cout << "currentFlow now is: " << getCurrentFlow() << endl;
     }
     m_maxFlow = getCurrentFlow(); //because after the last iteration, the flow is maximal
     setCut(dArr);// now it is possible to set the minCut.
     delete[]dArr;
     return m_maxFlow;
}

int FlowNetwork::getCurrentFlow()
{
     m_currentFlow = 0;
     int sVertex = m_graph.getSvertex();
     for (int i = 0; i < m_graph.getNumOfVertexes(); i++)
     {
          m_currentFlow += m_graph.getEdgeFlow(sVertex, i);
     }
     return m_currentFlow;
}

void FlowNetwork::setCut(int* i_dArray)
{
     int numOfVertexes = m_graph.getNumOfVertexes();
     for (int i = 0; i < numOfVertexes; i++)
     {
          if (i_dArray[i] == INFINITY_val)
          {
               m_minCut.addVertexToT(i);
          }
          else 
          {
               m_minCut.addVertexToS(i);
          }
     }
}

void FlowNetwork::printFlowNetwork()
{
     m_graph.printGraph();
     m_minCut.showCut();

     cout << endl << "current flow is: " << m_currentFlow << endl;
}
