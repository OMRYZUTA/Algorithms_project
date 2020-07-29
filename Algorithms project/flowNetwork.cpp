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
               i_dArr[i] = INFINITY_VAL;  // init the arr. -1 = infinty
               pArr[i] = NO_PARENT; // to indicate that there is no parent
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
                    if (i_dArr[v] == INFINITY_VAL) // -1= infinity
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
     while (tempParent != NO_PARENT)
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
     m_numOfiterations = 0;
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
          ++m_numOfiterations;
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

int FlowNetwork::fordFulkersonMethodWithDijskstraVaration()
{
     m_numOfiterations = 0;
     int arrSize = m_graph.getNumOfVertexes();
     int* dArr = new int[arrSize];
     int* tempParentsArray = nullptr;
     tempParentsArray = DijskstraVarationMethod();
     List tempRouteFromStoT = findRouteFromStoT(tempParentsArray);
     int tempMinCf = 0;
     while (!tempRouteFromStoT.isEmpty())
     {
          tempMinCf = findMinCfInRoute(tempRouteFromStoT);
          increaseFlow(tempRouteFromStoT, tempMinCf);
          tempParentsArray = DijskstraVarationMethod();
          tempRouteFromStoT = findRouteFromStoT(tempParentsArray); //move operator =
          ++m_numOfiterations;
     }
     m_maxFlow = getCurrentFlow(); //because after the last iteration, the flow is maximal
     BFS(dArr);
     setCut(dArr);// now it is possible to set the minCut.
     delete[]dArr;
     return m_maxFlow;

}

int* FlowNetwork::DijskstraVarationMethod()
{
     // creating array in order to create maxHeap
     int* pArray = new int[m_graph.getNumOfVertexes()];
     int* dArray = new int[m_graph.getNumOfVertexes()];
     HeapElement* heapElementsArray = new HeapElement[m_graph.getNumOfVertexes()];
     initialzeSingleSource(heapElementsArray, pArray, dArray);
     MaxHeap maxHeap(heapElementsArray,m_graph.getNumOfVertexes());
     //delete later:
     maxHeap.printHeap();
     int tempVertex;

     while (!maxHeap.IsEmpty())
     {
          tempVertex = maxHeap.DeleteMax();
          // for each v that is neighbor of tempVertex
          List neighbors = m_graph.getAdjListByCapacity(tempVertex);
          Node* tempNeighbor = neighbors.getHead();
          while (tempNeighbor)
          {
               relax(tempVertex, tempNeighbor->getData(), pArray, maxHeap, dArray);
               tempNeighbor = tempNeighbor->getNext();
          }
     }
     //delete later:
     for (int i = 0; i < m_graph.getNumOfVertexes(); i++)
     {
          cout << " " << pArray[i]+1;

     }

     return pArray; 
}

void FlowNetwork::initialzeSingleSource(HeapElement* i_ElementHeapArray, int* i_pArray,  int* i_dArray)
{
     for (int i = 0; i < m_graph.getNumOfVertexes(); i++)
     {
          i_ElementHeapArray[i].setdata(i);
          i_ElementHeapArray[i].setkey(INFINITY_VAL);
          i_dArray[i]=INFINITY_VAL;
          i_pArray[i] = NO_PARENT;
     }
     i_ElementHeapArray[m_graph.getSvertex()].setkey(0);// maybe because we use max heap we need to make it something else. delete later
}

void FlowNetwork::relax(int i_uVertex, int i_vVertex , int* i_pArray, MaxHeap & i_maxHeap, int * i_dArray)
{
     int edgeUvCF = m_graph.getEdgeCf(i_uVertex, i_vVertex);
     int pathThroughUCF = min(i_dArray[i_uVertex], edgeUvCF);
     // checks if the path to v vertex has a no cf 
     if (i_dArray[i_vVertex] == INFINITY_VAL)
     {
          if (i_uVertex == m_graph.getSvertex())
          {
               i_dArray[i_vVertex] = edgeUvCF;
               i_pArray[i_vVertex] = i_uVertex;
          }
          else
          {
               i_dArray[i_vVertex] = pathThroughUCF;
               i_pArray[i_vVertex] = i_uVertex;
          }
          i_pArray[i_vVertex] = i_uVertex;
        //increase key
          i_maxHeap.IncreaseKey(i_vVertex, i_dArray[i_vVertex]);

     }
     //or less cf the if it uses u vertex
     else if (pathThroughUCF > i_dArray[i_vVertex])
     {
          i_dArray[i_vVertex]=pathThroughUCF;
          i_pArray[i_vVertex] = i_uVertex;
          //increase key
          i_maxHeap.IncreaseKey(i_vVertex, i_dArray[i_vVertex]);
     }
}

void FlowNetwork::setCut(int* i_dArray)
{
     int numOfVertexes = m_graph.getNumOfVertexes();
     for (int i = 0; i < numOfVertexes; i++)
     {
          if (i_dArray[i] == INFINITY_VAL)
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
     cout << "Max flow = " << m_maxFlow << endl;
     m_minCut.showCut();
     cout << "Number of iterations = " << m_numOfiterations << endl;

     
}

int FlowNetwork::min(int num1, int num2)
{
     if (num1 < num2)
     {
          return num1;
     }
     return num2;
}
