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
     Graph g;
     int maxFlow;
     int currFlow;
     Cut mincut;
public:
     FlowNetwork();
     FlowNetwork(Graph g, int maxflow = 0, int currflow = 0);
     FlowNetwork(FlowNetwork& other);
     ~FlowNetwork();
     List BFS();
};








#endif