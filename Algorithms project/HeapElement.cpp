#include "HeapElement.h"
#pragma warning(disable : 4996)


HeapElement::HeapElement()
{
	m_data = 0;
	m_key = 0; 
}

HeapElement::HeapElement(int i_data, int i_key)
{
	m_data = i_data;
	m_key = i_key;
}

HeapElement::HeapElement(HeapElement& i_other)
{
	m_data = i_other.m_data;
	m_key = i_other.m_key;
}

HeapElement::~HeapElement()
{

}

void HeapElement::setdata(int i_HeapElementData)
{
	m_data = i_HeapElementData;
}

void HeapElement::setkey(int i_HeapElementkey)
{
	m_key = i_HeapElementkey;
}

int HeapElement::getdata()
{
	return m_data;
}

int HeapElement::getkey()
{
	return m_key;
}