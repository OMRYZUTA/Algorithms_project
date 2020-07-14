#ifndef __CUT_H
#define __CUT_H
#pragma warning (diable: 4996)
#include <iostream>


class Cut
{
private:
     int* S;
     int* T;  //two groups of vertexes
     int sizeOfS;
     int sizeOfT; 
public:
     Cut();
     Cut(int* S, int* T);
     Cut(Cut& other);
     ~Cut();
};








#endif