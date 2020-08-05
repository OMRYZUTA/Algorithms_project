#ifndef __NODE_H
#define __NODE_H

#include <stdlib.h>
#include <iostream>
using namespace std;

class Node
{
private:
	int m_data;                                 
	Node* m_next;                                   //next Node in the list

public:
	Node();                                       // Default c'tor
	Node(int i_data, Node* i_nextNode);                  // c'tor
	Node(Node* i_OtherNode);                            // copy c'tor
	virtual	~Node();                                      // d'tor
	void insertAfter(Node* i_newNodeToAdd);              // Insert Node after current Node
	Node* deleteAfter(Node* i_deleteAfterThisNode);             // Delete Node after current Node

	Node* getNext();
	int getData();
	void setData(int i_data);
	void setNextNode(Node* i_NextNode);
};
#endif // __NODE_H