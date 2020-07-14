#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdlib.h>
#include <iostream>
#include "Node.h"
using namespace std;


class Queue
{
private:
	Node* head;
	Node* tail;

public:
	Queue();                                       // c'tor
	Queue(Node* h, Node* t);                       // c'tor
	Queue(Queue& other);                           // copy c'tor
	~Queue();                                      // d'tor
	void makeEmpty();
	bool isEmpty();
	void enqueue(int n);
	int dequeue();
};
#endif // __QUEUE_H
