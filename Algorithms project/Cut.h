#ifndef __CUT_H
#define __CUT_H
#pragma warning (diable: 4996)
#include <iostream>
using namespace std;

class Cut
{
private:
     int* m_sGroupOfVertexes;
     int* m_tGroupOfVertexes;  //two groups of vertexes
     int m_sizeOfS;
     int m_sizeOfT; 
public:
     Cut();//default c'tor
     //Cut(int* i_SgroupOfVertexes, int* i_TgroupOfVertexes);// c'tor
     Cut(Cut& i_otherCut);//copy c'tor
     Cut(Cut&& i_otherCut);//move c'tor
     ~Cut();
     void showCut();
};








#endif