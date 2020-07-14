#ifndef __NODE_H
#define __NODE_H

#include <stdlib.h>
#include <iostream>
using namespace std;

class Node
{
private:
	int data;                                 
	Node* next;                                   //next Node in the list

public:
	Node();                                       // Default c'tor
	Node(int d, Node* nextNode);                  // c'tor
	Node(Node* other);                            // copy c'tor
	~Node();                                      // d'tor
	void insertAfter(Node* newNode);              // Insert Node after current Node
	Node* deleteAfter(Node* newNode);             // Delete Node after current Node
	int getData();
	friend class List;
	friend class Queue;
};
#endif // __NODE_H