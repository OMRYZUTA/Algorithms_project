#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdlib.h>
#include <iostream>
#include "Node.h"
using namespace std;


class Queue
{
private:
	Node* m_head;
	Node* m_tail;

public:
	Queue();                                       // c'tor
	
	Queue(Queue& i_otherQueue);                           // copy c'tor
	virtual	~Queue();                                      // d'tor
	void makeEmpty();
	bool isEmpty();
	void enqueue(int i_data);
	int dequeue();
};
#endif // __QUEUE_H
