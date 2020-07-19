#ifndef __LIST_H
#define __LIST_H

#include <stdlib.h>
#include <iostream>
#include "Node.h"
using namespace std;

class List
{
private:
	Node* head;
	Node* tail;

public:
	List();                                       // Default c'tor
	List(Node* h, Node* t);                       // c'tor
	List(List& other);                            // copy c'tor
	List(List&& other);                           // move c'tor
	~List();                                      // d'tor
	void addNodeToTail(int n);
	void addNodeToHead(int n);
	Node* getHead();
	void printList();              	
};
#endif // __LIST_H