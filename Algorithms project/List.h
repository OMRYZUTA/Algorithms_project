#ifndef __LIST_H
#define __LIST_H

#include <stdlib.h>
#include <iostream>
#include "Node.h"
using namespace std;

class List
{
private:
	Node* m_head;
	Node* m_tail;

public:
	List();                                       // Default c'tor
	List(Node* i_head, Node* i_tail);                       // c'tor
	List(List& i_otherList);                            // copy c'tor
	List(List&& i_otherList);                           // move c'tor
	~List();             // d'tor

	const List& operator=(List&& i_otherList);

	void addNodeToTail(int i_data);
	void addNodeToHead(int i_data);
	Node* getHead();

	bool isEmpty();
	void makeEmpty();
	void printList();              	
};
#endif // __LIST_H