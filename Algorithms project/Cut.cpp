#include "Cut.h"
#pragma warning(disable : 4996)

Cut::Cut()
{


}
//Cut::Cut(int* S, int* T)
//{
//	this->S = S;
//	this->T = T; //maybe doing new in here?
//}
// to delete later?

Cut::Cut(Cut& i_otherCut):m_sGroupOfVertexes(i_otherCut.m_sGroupOfVertexes)
,m_tGroupOfVertexes(i_otherCut.m_tGroupOfVertexes)
{
	
}
// to delete later?
Cut::Cut(Cut&& other)
{

}

Cut::~Cut()
{

}

void Cut::showCut()
{
	cout << "Min Cut : S = ";
	Node* printerNode = m_sGroupOfVertexes.getHead();
	if (!(printerNode))
	{
		cout << " Error! S is empty";
		exit(1);
	}
	while(printerNode){
		cout << printerNode->getData();
		if (printerNode->getNext())
		{
			cout <<", " ;
		}
		else
		{
			cout << ".";
		}
		printerNode = printerNode->getNext();
	}
	printerNode = m_tGroupOfVertexes.getHead();
	if (!(printerNode))
	{
		cout << " Error! T group  is empty";
		exit(1);
	}
	cout << "  T = ";
	while(printerNode)
	{
		cout << printerNode->getData();
		if (printerNode->getNext())
		{
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
		printerNode = printerNode->getNext();
	}

}

void Cut::addVertexToS(int i_vertex)
{
	m_sGroupOfVertexes.addNodeToTail(i_vertex);
}

void Cut::addVertexToT(int i_vertex)
{
	m_tGroupOfVertexes.addNodeToTail(i_vertex);
}
