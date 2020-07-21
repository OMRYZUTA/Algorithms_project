#include "Cut.h"
#pragma warning(disable : 4996)

Cut::Cut()
{
	m_sGroupOfVertexes = nullptr;
	m_tGroupOfVertexes = nullptr;
	m_sizeOfS = 0;
	m_sizeOfT = 0;
}
//Cut::Cut(int* S, int* T)
//{
//	this->S = S;
//	this->T = T; //maybe doing new in here?
//}
// to delete later?

Cut::Cut(Cut& other)
{
	m_sizeOfS = other.m_sizeOfS;
	m_sizeOfT = other.m_sizeOfT;
	m_sGroupOfVertexes = new int [other.m_sizeOfS];
	for (int i = 0; i < other.m_sizeOfS; i++)
	{
		m_sGroupOfVertexes[i] = other.m_sGroupOfVertexes[i];

	}
	m_tGroupOfVertexes = new int[other.m_sizeOfT];
	for (int i = 0; i < other.m_sizeOfT; i++)
	{
		m_tGroupOfVertexes[i] = other.m_tGroupOfVertexes[i];

	}
}
// to delete later?
Cut::Cut(Cut&& other)
{
	m_sizeOfS = other.m_sizeOfS;
	m_sizeOfT = other.m_sizeOfT;
	m_sGroupOfVertexes = other.m_sGroupOfVertexes;
	m_tGroupOfVertexes = other.m_tGroupOfVertexes;
	other.m_sGroupOfVertexes = nullptr;
	other.m_tGroupOfVertexes = nullptr;
}

Cut::~Cut()
{
	delete[] m_sGroupOfVertexes; // if S or T is null, nothing happen
	delete[]m_tGroupOfVertexes;
}