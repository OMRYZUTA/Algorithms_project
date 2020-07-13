#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
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
void main(int argc, char* argv[])
{
     int numOfVertex, numOfAdjes, s, t;
     ifstream inFile(argv[1]); // opening file called "input.txt"
     inFile >> numOfVertex >> numOfAdjes>> s>> t;  //init those variables

     cout <<"num Of Vertex is: " <<numOfVertex << " num Of Adjes is: " 
          << numOfAdjes << " s Vertex is: " <<s << " t  Vertex is: " <<t;
     inFile.close();




}