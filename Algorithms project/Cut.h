#ifndef __CUT_H
#define __CUT_H
#pragma warning (diable: 4996)

#include <iostream>

#include "List.h"

using namespace std;

class Cut
{
private:
     List m_sGroupOfVertexes;
     List m_tGroupOfVertexes;  //two groups of vertexes

public:
     Cut();//default c'tor
     //Cut(int* i_SgroupOfVertexes, int* i_TgroupOfVertexes);// c'tor
     Cut(Cut& i_otherCut);//copy c'tor
     
   virtual  ~Cut();
     void showCut();
     void addVertexToS(int i_vertex);
     void addVertexToT(int i_vertex);
};








#endif