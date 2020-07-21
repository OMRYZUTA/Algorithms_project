#include "Node.h"
#pragma warning(disable : 4996)

Node::Node()
{
	m_data = 0;
	m_next = nullptr;
}

Node::Node(int i_data, Node* i_nextNode)
{
	m_data = i_data;	
	m_next = i_nextNode;
}

Node::Node(Node* i_otherNode)
{
	this->m_data = i_otherNode->getData();
	this->m_next = i_otherNode->getNext();
}

Node::~Node()
{
}

void Node::insertAfter(Node* i_newNode)
{
	i_newNode->m_next = m_next;
	m_next = i_newNode;
}

Node* Node::deleteAfter(Node* i_newNode)
{
	Node* temp = m_next;
	if (m_next == nullptr) // If the current Node is the last Node
		return nullptr;

	m_next = temp->getNext();   // If the current Node is NOT the last Node
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

void Node::setData(int i_data)
{
	m_data = i_data;
}

void Node::setNextNode(Node* i_NextNode)
{
	m_next = i_NextNode;
}
