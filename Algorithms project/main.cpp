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
     ifstream inFile("input3.txt"); // opening file called "input.txt"
     inFile >> m_numOfVertexes >> numOfAdjes >> m_sVertex >> m_tVertex;  //initialize those variables
     Graph g1(m_numOfVertexes, numOfAdjes, m_sVertex - 1, m_tVertex - 1); // minus 1 for 
     int fileInputVertex, fileInputneighbor, fileInputEdgeCapacity;
     for (int i = 0; i < numOfAdjes; i++)
     {
          inFile >> fileInputVertex >> fileInputneighbor >> fileInputEdgeCapacity;
          // in the input file the vertex starts from 1. therefor the minus 1
          g1.addEdgeCapacity(fileInputVertex - 1, fileInputneighbor - 1, fileInputEdgeCapacity);
     }
     /*        cout <<"number Of Vertexes is: " <<m_numOfVertexes <<
                  " number Of edges is: "
                  << numOfAdjes << " s Vertex is: " << m_sVertex
                  << " t  Vertex is: " << m_tVertex <<endl;
             g1.printGraph();*/
     FlowNetwork flow1(g1);
     /*    cout << "BFS Method:\n";

         flow1.fordFulkersonMethodWithBFS();
         flow1.printFlowNetwork();*/
     HeapElement h1(1,2), h2(2, 3), h3(3, 4), h4(4,5), h5(5,6);
     HeapElement* A = new HeapElement[5];
     A[0] = h1;
     A[1] = h2; 
     A[2] = h3;
     A[3] = h4;
     A[4] = h5;
          MaxHeap testHeap(A,5);
          cout << "the max Node is: " << testHeap.DeleteMax() << endl;
          HeapElement a(7, 10);
          testHeap.Insert(a);
          cout << "the max Node NOWWW is: " << testHeap.DeleteMax() << endl;
          testHeap.DeleteMax();
          testHeap.DeleteMax();
          testHeap.DeleteMax();
          testHeap.DeleteMax();
          if (testHeap.IsEmpty())
          {
               cout << "Heap is empty!";
          }
          MaxHeap testHeap2(A, 5);
          testHeap2.IncreaseKey(4, 10);
          cout << "the Max is" << testHeap.Max();
          testHeap2.swap(h1, h2);

}