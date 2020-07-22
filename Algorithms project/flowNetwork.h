#ifndef __FLOW_NETWORK_H
#define __FLOW_NETWORK_H
#pragma warning (diable: 4996)
#include <iostream>
#include "Graph.h"
#include "Cut.h"
#include "List.h"

using namespace std;

class FlowNetwork
{
private:
     Graph m_graph;
     int m_maxFlow;
     int m_currentFlow;
     Cut m_minCut;
     
public:
     FlowNetwork();
     FlowNetwork(Graph i_graph, int i_maxflow = 0, int i_currentflow = 0);
     FlowNetwork(FlowNetwork& i_otherFlowNetwork);
     ~FlowNetwork();
     List BFS();
};








#endif