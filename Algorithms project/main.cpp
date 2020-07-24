#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>


#include "FlowNetwork.h"
using namespace std;

// This program gets text file with graph and the graph data.
// the program will make a Flow network
// the maximum flow of the Flow network will be printed,
// and also, its minimal cut.
// the program will use 2 different searching methods:
//BFS and with a greedy method

// argc count how much arguments have been sent to main
// argv is the arguments itself, represented as string
// it's comfortable to debug this program with cmd : Algorithms_project input.txt

// we will save this main for the end of the project, handling with file
// for the meantime, lets check every bit of code that we write

//void main(int argc, char* argv[])
//{
//     
//     int numOfVertex, numOfAdjes, s, t;
//     ifstream inFile(argv[1]); // opening file called "input.txt"
//     inFile >> numOfVertex >> numOfAdjes>> s>> t;  //init those variables
//     Graph g1(numOfVertex, numOfAdjes, s-1, t-1); // minus 1 for 
//     int tempV, tempU, tempC;
//     for (int i = 0; i < numOfAdjes; i++)
//     {
//          inFile >> tempV >> tempU >> tempC;
//          // in the input file the vertex starts from 1. therfor the minus 1
//          g1.addEdge(tempV-1,tempU-1, tempC);
//     }
//     cout <<"num Of Vertex is: " <<numOfVertex << " num Of Adjes is: " 
//          << numOfAdjes << " s Vertex is: " <<s << " t  Vertex is: " <<t<<endl;
//     g1.printGraph();
//     inFile.close();
//
//}

void main()
{
    

     int m_numOfVertexes, numOfAdjes, m_sVertex, m_tVertex;
          ifstream inFile("input.txt"); // opening file called "input.txt"
          inFile >> m_numOfVertexes >> numOfAdjes>> m_sVertex >> m_tVertex;  //initialize those variables
          Graph g1(m_numOfVertexes, numOfAdjes, m_sVertex -1, m_tVertex -1); // minus 1 for 
          int fileInputVertex, fileInputneighbor, fileInputEdgeCapacity;
          for (int i = 0; i < numOfAdjes; i++)
          {
               inFile >> fileInputVertex >> fileInputneighbor >> fileInputEdgeCapacity;
               // in the input file the vertex starts from 1. therefor the minus 1
               g1.addEdgeCapacity(fileInputVertex -1, fileInputneighbor -1, fileInputEdgeCapacity);
          }
          cout <<"number Of Vertexes is: " <<m_numOfVertexes <<
               " number Of edges is: " 
               << numOfAdjes << " s Vertex is: " << m_tVertex
               << " t  Vertex is: " << m_tVertex <<endl;
          g1.printGraph();
          FlowNetwork flow1(g1);
          List l1 =flow1.findRouteFromStoT(flow1.BFS());
          l1.printList();
          
}