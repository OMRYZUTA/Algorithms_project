#include "Node.h"
#pragma warning(disable : 4996)

Node::Node()
{
	this->next = nullptr;
}

Node::Node(int d, Node* nextNode)
{
	this->data = d;	
	this->next = nextNode;
}

Node::Node(Node* other)
{
	this->data = other->data;
	this->next = other->next;
}

Node::~Node()
{
}

void Node::insertAfter(Node* newNode)
{
	newNode->next = next;
	next = newNode;
}

Node* Node::deleteAfter(Node* newNode)
{
	Node* temp = next;
	if (next == nullptr) // If the current Node is the last Node
		return nullptr;

	next = temp->next;   // If the current Node is NOT the last Node
	return temp;
}
Node* Node::getNext()
{
	return next;
}
int Node::getData()
{
	return data;
}