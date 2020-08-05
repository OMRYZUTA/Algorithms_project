#include "flowNetwork.h"
#include "Queue.h"
#pragma warning(disable : 4996)

FlowNetwork::FlowNetwork():m_graph(),m_minCut()
{
     m_maxFlow  = m_currentFlow=0;
     m_numOfiterations = 0;
}

FlowNetwork::FlowNetwork(Graph i_graph, int i_maxflow, int i_currentflow):m_graph(i_graph),m_minCut()
{
     m_maxFlow = i_maxflow;
     m_currentFlow = i_currentflow;
     m_numOfiterations = 0;
}

FlowNetwork::FlowNetwork(FlowNetwork& i_otherFlowNetwork):m_graph(i_otherFlowNetwork.m_graph),m_minCut(i_otherFlowNetwork.m_minCut)
{
    m_maxFlow = i_otherFlowNetwork.m_maxFlow;
    m_currentFlow =i_otherFlowNetwork.m_currentFlow;
    m_numOfiterations = i_otherFlowNetwork.m_numOfiterations;
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
               i_dArr[i] = INFINITY_VAL;  // init the arr. -1 = infinty to indicate that there is no route between s to this vertex
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
     while (tempVertexV) // running through all the list and searching for the minimal CF
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
     int count = 0;
     while (tempParent != NO_PARENT)
     {
          // adding form t to his parents , using add node to head so in the end s will be the first and t will be the last
          routeFromStoT.addNodeToHead(tempParent);
          tempParent = i_pArr[tempParent];
          count++;
          if (tempParent==m_graph.getSvertex())
          { 
               routeFromStoT.addNodeToHead(tempParent);
               break; // we need a route that s is his head
          }
          if (count > m_graph.getNumOfVertexes())
          {
               break;
               // not possible to have a route that longer than number of vertexes in graph
          }

     }
     // return List that represent path of vertexes from s to t 
     if (routeFromStoT.getHead()->getData() != m_graph.getSvertex())
     {
          // no need for a list that s is not the head
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
          tempVertexV = tempVertexU->getNext(); 
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
     // initiating
     tempParentsArray = BFS(dArr);
     List tempRouteFromStoT = findRouteFromStoT(tempParentsArray);
     int tempMinCf = 0;
     while (!tempRouteFromStoT.isEmpty()) // main loop, running as long as there is a route that can improve the flow from s to t
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

int FlowNetwork::getCurrentFlow() // collecting from all the edges (s,v) so that v is neighbor of s
{
     m_currentFlow = 0;
     int sVertex = m_graph.getSvertex();
     for (int i = 0; i < m_graph.getNumOfVertexes(); i++)
     {
          m_currentFlow += m_graph.getEdgeFlow(sVertex, i);
     }
     return m_currentFlow;
}

int FlowNetwork::fordFulkersonMethodWithDijskstraVariation()
{
     m_numOfiterations = 0;
     int arrSize = m_graph.getNumOfVertexes();
     int* dArr = new int[arrSize];
     int* tempParentsArray = nullptr;
     // initiating:
     tempParentsArray = DijskstraVarationMethod(dArr);
     List tempRouteFromStoT = findRouteFromStoT(tempParentsArray);
     int tempMinCf = 0;
     while (!tempRouteFromStoT.isEmpty())
     {
          tempMinCf = findMinCfInRoute(tempRouteFromStoT);
          increaseFlow(tempRouteFromStoT, tempMinCf);
          tempParentsArray = DijskstraVarationMethod(dArr);
          tempRouteFromStoT = findRouteFromStoT(tempParentsArray); //move operator =
          ++m_numOfiterations;
     }
     m_maxFlow = getCurrentFlow(); //because after the last iteration, the flow is maximal
    int* tempPArr= BFS(dArr);
    delete[] tempPArr;
     setCut(dArr);// now it is possible to set the minCut.
     delete[]dArr;

     return m_maxFlow;
}

int* FlowNetwork::DijskstraVarationMethod(int* i_dArray)
{
     // creating array in order to create maxHeap 
     int* pArray = new int[m_graph.getNumOfVertexes()];               
     // initiating:
     HeapElement* heapElementsArray = new HeapElement[m_graph.getNumOfVertexes()];
     initialzeSingleSource(heapElementsArray, pArray, i_dArray);
     MaxHeap maxHeap(heapElementsArray,m_graph.getNumOfVertexes());
 
     int tempVertex;

     while (!maxHeap.IsEmpty()) // main loop
     {
          tempVertex = maxHeap.DeleteMax();
          // for each v that is neighbor of tempVertex
          List neighbors = m_graph.getAdjListByCapacity(tempVertex);
          Node* tempNeighbor = neighbors.getHead();
          while (tempNeighbor)// setting the order in the heap between temp vertex and his neighbor
          {
               relax(tempVertex, tempNeighbor->getData(), pArray, maxHeap, i_dArray);
               tempNeighbor = tempNeighbor->getNext();

          }

     }
   
      delete[] heapElementsArray;
     return pArray; 
}
//setting the ground for Dijkstra algorithm
void FlowNetwork::initialzeSingleSource(HeapElement* i_ElementHeapArray, int* i_pArray,  int* i_dArray)
{
     for (int i = 0; i < m_graph.getNumOfVertexes(); i++)
     {
          i_ElementHeapArray[i].setdata(i);
          i_ElementHeapArray[i].setkey(INFINITY_VAL);
          i_dArray[i]=INFINITY_VAL;
          i_pArray[i] = NO_PARENT;
     }
     i_ElementHeapArray[m_graph.getSvertex()].setkey(INFINITY_INT);
	 i_dArray[m_graph.getSvertex()] = INFINITY_INT;    

 
}

void FlowNetwork::relax(int i_uVertex, int i_vVertex , int* i_pArray, MaxHeap & i_maxHeap, int * i_dArray)
{
     int edgeUvCF = m_graph.getEdgeCf(i_uVertex, i_vVertex); 
     int pathThroughUCF = min(i_dArray[i_uVertex], edgeUvCF);
     // checks if the path to v vertex has a no cf 
     if (i_dArray[i_vVertex] == INFINITY_VAL&& i_dArray[i_uVertex] != INFINITY_VAL)
     {
          if (i_uVertex == m_graph.getSvertex())
          {
               i_dArray[i_vVertex] = edgeUvCF;
          }
          else
          {
               i_dArray[i_vVertex] = pathThroughUCF;
          }
          i_pArray[i_vVertex] = i_uVertex;
        //increase key
          i_maxHeap.IncreaseKey(i_vVertex, i_dArray[i_vVertex]);

     }
     //or less cf the if it uses u vertex
     else if (pathThroughUCF > i_dArray[i_vVertex] && i_dArray[i_uVertex] != INFINITY_VAL) //            change 29.7 niv:          seems we dont need the above "if" at all! still need to check
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
          if (i_dArray[i] == INFINITY_VAL) // all the vertexes that have no connection to s are in T
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

int FlowNetwork::min(int i_num1, int i_num2)
{
     if (i_num1 < i_num2)
     {
          return i_num1;
     }
     return i_num2;
}
