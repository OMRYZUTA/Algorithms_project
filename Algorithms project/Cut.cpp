#include "Cut.h"
#pragma warning(disable : 4996)

Cut::Cut()
{
	S = nullptr;
	T = nullptr;
	sizeOfS = 0;
	sizeOfT = 0;
}
Cut::Cut(int* S, int* T)
{
	this->S = S;
	this->T = T; //maybe doing new in here?
}
// to delete later?
Cut::Cut(Cut& other)
{

}

Cut::~Cut()
{

}