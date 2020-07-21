#include "Node.h"
#pragma warning(disable : 4996)

Node::Node()
{
	this->m_next = nullptr;
}

Node::Node(int d, Node* nextNode)
{
	this->m_data = d;	
	this->m_next = nextNode;
}

Node::Node(Node* other)
{
	this->m_data = other->m_data;
	this->m_next = other->m_next;
}

Node::~Node()
{
}

void Node::insertAfter(Node* newNode)
{
	newNode->m_next = m_next;
	m_next = newNode;
}

Node* Node::deleteAfter(Node* newNode)
{
	Node* temp = m_next;
	if (m_next == nullptr) // If the current Node is the last Node
		return nullptr;

	m_next = temp->m_next;   // If the current Node is NOT the last Node
	return temp;
}
Node* Node::getNext()
{
	return m_next;
}
int Node::getData()
{
	return m_data;
}