#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include"Validator.h"

#include "FlowNetwork.h"
using namespace std;

// This program gets text file with graph and the graph data.
// the program will make a Flow network
// the maximum flow of the Flow network will be printed,
// and also, its minimal cut.
// the program will use 2 different searching methods:
//BFS and with a greedy method

// in the input.txt file, the first four parameters should be represented as numbers by this order exactly, with this newlines:
// number of Vertexes
// number of edges
// s vertex
// t vertex
// v vertex u vertex capacity between them - all the edges need to be in this format, each edge with new line
// s,t has to be more than 0 and less than number of vertexes
// negative capacity is illegal
// it has to be a simple graph
// argc count how much arguments have been sent to main
// argv is the arguments itself, represented as string

// it's comfortable to debug this program with cmd : Algorithms_project input.txt






void main(int argc, char* argv[])
{


     // checking spelling mistakes:
     Validator validator(argv[1]);
     validator.checkWholePageSpellCorrectness();
     validator.checkWholePageLogicly();
     int numOfVertexes, numOfAdjes, sVertex, tVertex;
     ifstream inFile(argv[1]); // opening file called "input.txt"
     inFile >> numOfVertexes >> numOfAdjes >> sVertex >> tVertex;  //initialize those variables
     Graph g1(numOfVertexes, numOfAdjes, sVertex - 1, tVertex - 1); // minus 1 for 
     int fileInputVertex, fileInputneighbor, fileInputEdgeCapacity;
     for (int i = 0; i < numOfAdjes; i++)
     {
          inFile >> fileInputVertex >> fileInputneighbor >> fileInputEdgeCapacity;
          // in the input file the vertex starts from 1. therefor the minus 1
          g1.addEdgeCapacity(fileInputVertex - 1, fileInputneighbor - 1, fileInputEdgeCapacity);
     }

     FlowNetwork flow1(g1);
         cout << "BFS Method:\n";

         flow1.fordFulkersonMethodWithBFS();
         flow1.printFlowNetwork();
         FlowNetwork flow2(g1);
         flow2.fordFulkersonMethodWithDijskstraVariation();
         cout << "Greedy Method:\n";
         flow2.printFlowNetwork();
         inFile.close();
}