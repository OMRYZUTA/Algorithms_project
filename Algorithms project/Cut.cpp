#include "Cut.h"
#pragma warning(disable : 4996)

Cut::Cut()
{
	S = nullptr;
	T = nullptr;
	sizeOfS = 0;
	sizeOfT = 0;
}
//Cut::Cut(int* S, int* T)
//{
//	this->S = S;
//	this->T = T; //maybe doing new in here?
//}
// to delete later?

Cut::Cut(Cut& other)
{
	sizeOfS = other.sizeOfS;
	sizeOfT = other.sizeOfT;
	S = new int [other.sizeOfS];
	for (int i = 0; i < other.sizeOfS; i++)
	{
		S[i] = other.S[i];

	}
	T = new int[other.sizeOfT];
	for (int i = 0; i < other.sizeOfT; i++)
	{
		T[i] = other.T[i];

	}
}
// to delete later?
Cut::Cut(Cut&& other)
{
	sizeOfS = other.sizeOfS;
	sizeOfT = other.sizeOfT;
	S = other.S;
	T = other.T;
	other.S = nullptr;
	other.T = nullptr;
}

Cut::~Cut()
{
	delete[] S; // if S or T is null, nothing happen
	delete[]T;
}