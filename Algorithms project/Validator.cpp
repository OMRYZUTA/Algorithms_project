#include "Validator.h"
#pragma warning(disable : 4996)
// opening file called "input.txt"
Validator::Validator(const char* i_fileName)
{
     m_fileName = i_fileName;
     
}

Validator::~Validator()
{

}

// no need to check if it's negative cause the spelling check will catch '-' anyway
void Validator::checkWholePageLogicly()
{
     int numOfVertexes, numOfEdges, sVertex, tVertex;
     ifstream inFile(m_fileName); // opening file called "input.txt"
     inFile >> numOfVertexes >> numOfEdges >> sVertex >> tVertex;  //initialize those variables

     // if its there is more Edges than vertexes squared , it's not a simple graph
     if (numOfVertexes * numOfVertexes <= numOfEdges)
     {
          cout << "Error! too much Edges for a simple graph!";
               exit(1);
     }
     if (numOfVertexes == 0)
     {
          cout << "Error! it's not a graph without any vertexes";
          exit(1);
     }
     if (sVertex > numOfVertexes || sVertex == 0)
     {
          cout << "Error! s vertex is inserted wrongly ";
          exit(1);
     }
     if (tVertex > numOfVertexes || tVertex == 0)
     {
          cout << "Error! t vertex is inserted wrongly ";
          exit(1);
     }
     Graph g1(numOfVertexes, numOfEdges, sVertex - 1, tVertex - 1); // minus 1 for 
     int fileInputVertex, fileInputneighbor, fileInputEdgeCapacity;
     int i;
     for (i = 0;  inFile >> fileInputVertex; i++)// if reached eof, we want try to read
     {
          inFile  >> fileInputneighbor >> fileInputEdgeCapacity;
          if (fileInputneighbor == fileInputVertex)
          {
               cout << "Error! no self loops, it's a simple graph";
               exit(1);
          }
          if (fileInputEdgeCapacity == 0)
          {
               cout << "Error! no 0 capacity in this project";
               exit(1);
          }
          if (g1.getEdgeCf(fileInputVertex - 1, fileInputneighbor - 1) != 0)
          {
               cout << "Error! no parallel edges in a simple graph! ";
               exit(1);
          }
          // in the input file the vertex starts from 1. therefor the minus 1
          g1.addEdgeCapacity(fileInputVertex - 1, fileInputneighbor - 1, fileInputEdgeCapacity);
     }
     if (numOfEdges != i)
     {
          cout << "Error! the number of rows doesn't equal to the number of the edges";
          exit(1);
     }
     inFile.close();
}

void Validator::checkWholePageSpellCorrectness()
{
     
     // checking spell in the first 4 inputs
     ifstream inFile(m_fileName); // opening file called "input.txt"
     char charChecker1;
     bool isNewLine = true;

     int numCounter = 0;
     bool isTabOrSpace = false;
     bool isNum = false;
     inFile >> std::noskipws;
     while (inFile >> charChecker1 && isNewLine )
     {
          if (charChecker1 < '0' || charChecker1>'9')
          {
               if (charChecker1 == '\n')
               {
                    isNewLine = true;
                    isTabOrSpace = false;
                    if (isNum)
                    {
                         numCounter++;
                         isNum = false;
                    }
               }
               else if (charChecker1 == ' ' || charChecker1 == '\t')
               {

                    if (isNum)
                    {
                         isTabOrSpace = true;
                         numCounter++;
                         isNum = false;
                    }
               }

               else
               {
                    isNewLine = false;
                    cout << "Error " << charChecker1 << " is not numeric or whitespace input entered" << endl;
                    exit(1);
               }
          }
          else if (!isNum)
          {
               if (isTabOrSpace)
               {
                    cout << "Error! there isn't new line between first 4 parameters";
                    exit(1);
               }
               isNum = true;
               isTabOrSpace = false;
          }
          if (numCounter >= 4)
          {
               break;
          }
     }
     if (numCounter < 4)
     {
          cout << "Error! there is less then 4 numbers in an input row" << endl;
          exit(1);
     }
     int numCounterInLine = 0;
     while (inFile >> charChecker1 && isNewLine && numCounterInLine < 4)
          {
         
               if (charChecker1 < '0' || charChecker1>'9')
               {
                    if (charChecker1 == '\n')
                    {
                         isNewLine = true;
                         isTabOrSpace = false;
                         if (isNum)
                         {
                              numCounterInLine++;
                             
                              
                              
                         }
                         if (numCounterInLine < 3 && numCounterInLine != 0)
                         {
                              cout << "Error! only " << numCounterInLine << " numbers in line";
                              exit(1);
                         }
                         isNum = false;
                         numCounterInLine = 0;
                    }
                    else if (charChecker1 == ' ' || charChecker1 == '\t')
                    {

                         if (isNum)
                         {
                              isTabOrSpace = true;
                              numCounterInLine++;
                              isNum = false;
                         }
                    }

                    else
                    {
                         isNewLine = false;
                         cout << "Error " << charChecker1 << " is not numeric or whitespace input entered" << endl;
                         exit(1);
                    }
               }
               else if (!isNum)
               {
            
                    isNum = true;
                    isTabOrSpace = false;
               }
          }
     if (numCounterInLine > 3)
     {
          cout << "Error! there is more then 3 numbers in an  input row" << endl;
          exit(1);
     }

     inFile.close();
}





