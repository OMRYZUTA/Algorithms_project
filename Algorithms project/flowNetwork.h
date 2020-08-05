#ifndef __FLOW_NETWORK_H
#define __FLOW_NETWORK_H
#pragma warning (diable: 4996)

#include <iostream>

#include "Graph.h"
#include "List.h"
#include "Queue.h"
#include "MaxHeap.h"
#include <limits>

using namespace std;
constexpr int INFINITY_INT = std::numeric_limits<int>::max();
constexpr int INFINITY_VAL = -1;
constexpr int NO_PARENT = -2;
class FlowNetwork
{
private:
     Graph m_graph;
     int m_maxFlow;
     int m_currentFlow;
     Cut m_minCut;
     int m_numOfiterations;
     
public:
     FlowNetwork();// default c'tor
     FlowNetwork(Graph i_graph, int i_maxflow = 0, int i_currentflow = 0); // c'tor
     FlowNetwork(FlowNetwork& i_otherFlowNetwork); // copy c'tor
     virtual ~FlowNetwork(); //d'tor
     
     
     
     int* BFS(int * i_dArray); // running bfs method on the graph
     int findMinCfInRoute(List i_trackFromStoT);// finds the edge with minimal cf and return the cf
     List findRouteFromStoT(int* i_pArr); // return lists that its head is s and the tail is t
     void increaseFlow(List i_trackFromStoT, int i_flowToIncrease);// going through the list and increase eace edge with the given flow
     int fordFulkersonMethodWithBFS();// algorithm that uses BFS to find the maximal flow thats possible
     int  getCurrentFlow();
     int fordFulkersonMethodWithDijskstraVariation();// algorithm that uses Dijkstra variation to find the maximal flow thats possible

     int* DijskstraVarationMethod(int* i_dArray);  // running Dijskstra Variation method on the graph
     void  initialzeSingleSource(HeapElement* i_ElementHeapArray, int* i_pArray ,int* i_dArray); // initiating arrays in order to use them in the Dijskstra Variation algorithm
     void relax(int i_uVertex, int i_vVertex,  int* i_pArray, MaxHeap& i_maxHeap, int *i_dArray);// function that apply the order between to elements in the heap
     void setCut(int* i_dArray);// setting the group T and S of the Cut
     void printFlowNetwork();
     int min(int i_num1, int i_num2);// finds minimum between 2 numbers
};








#endif