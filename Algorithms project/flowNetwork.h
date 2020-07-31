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
     FlowNetwork();
     FlowNetwork(Graph i_graph, int i_maxflow = 0, int i_currentflow = 0);
     FlowNetwork(FlowNetwork& i_otherFlowNetwork);
     ~FlowNetwork();
     
     
     
     int* BFS(int * i_dArray);
     int findMinCfInRoute(List i_trackFromStoT);
     List findRouteFromStoT(int* i_pArr);
     void increaseFlow(List i_trackFromStoT, int i_flowToIncrease);
     int fordFulkersonMethodWithBFS();
     int  getCurrentFlow();
     int fordFulkersonMethodWithDijskstraVaration();

     int* DijskstraVarationMethod(int* i_dArray);
     void  initialzeSingleSource(HeapElement* i_ElementHeapArray, int* i_pArray ,int* i_dArray);
     void relax(int i_uVertex, int i_vVertex,  int* i_pArray, MaxHeap& i_maxHeap, int *i_dArray);
     void setCut(int* i_dArray);
     void printFlowNetwork();
     int min(int i_num1, int i_num2);
};








#endif