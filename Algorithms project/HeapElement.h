#ifndef __HEAP_ELEMENT_H
#define __HEAP_ELEMENT_H
#pragma warning (diable: 4996)
#include <iostream>

using namespace std;

class HeapElement
{
private:
	int m_data;
	int m_key;

public:
	HeapElement();   //default c'tor
	HeapElement(int i_data, int i_key); //c'tor
	HeapElement(HeapElement& other);// copy c'tor
	~HeapElement();// d'tor
	void setdata(int i_HeapElementData);
    void setkey(int i_HeapElementkey);
	int getdata();
	int getkey();
};
#endif
