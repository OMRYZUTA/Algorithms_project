#include "List.h"
#pragma warning(disable : 4996)

List::List()
{
	m_head = nullptr;
	m_tail = nullptr;
}

List::List(Node* i_head, Node* i_tail)
{
	m_head = i_head;
	m_tail = i_tail;
}
//copy constructor
List::List(List& i_other)
{
	if (i_other.isEmpty())
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	else
	{
		Node* tempOldListNode = i_other.m_head;
		Node* builderListNode = new Node;
		// initializing head
		builderListNode->m_data = tempOldListNode->getData();
		m_head = builderListNode;
		tempOldListNode = tempOldListNode->getNext();
		while (tempOldListNode)
		{
			builderListNode->m_next = new Node;
			builderListNode = builderListNode->getNext();
			builderListNode->m_data = tempOldListNode->getData();
			tempOldListNode = tempOldListNode->getNext();
		}
		m_tail = builderListNode;
	}
}

List::List(List&& i_other) // move c'tor
{
	this->m_head = i_other.m_head;
	this->m_tail = i_other.m_tail;
	i_other.m_head = nullptr;
	i_other.m_head = nullptr;
}

// remember to delete all nodes properly. 
List::~List()
{	
	Node* tempListNode = m_head;
	Node* nextListNode = m_head->getNext();
	while (nextListNode) // run through all the list
	{
		delete tempListNode;
		tempListNode = nextListNode;
		nextListNode = tempListNode->getNext();
	}
	m_head = nullptr; // to avoid double deletes bugs
	m_tail = nullptr;
}

void List::addNodeToTail(int n)
{
	Node* tmp = new Node;
	tmp->m_data = n;
	tmp->m_next = nullptr;

	if (m_head == nullptr)
	{
		m_head = tmp;
		m_tail = tmp;
	}
	else
	{
		m_tail->m_next = tmp;
		m_tail = m_tail->m_next;
	}
}

bool List::isEmpty()
{
	return (m_head ==nullptr);
}

void List::printList()
{
	Node* currListNode = m_head;
	while (currListNode != nullptr)
	{
		cout << currListNode->m_data << "  ";
		currListNode = currListNode->m_next;
	}
	cout << endl;
}

Node* List::getHead()
{
	return m_head;
}

void List::addNodeToHead(int i_data)
{
	Node* tempListNode = new Node;
	tempListNode->m_data = i_data;
	tempListNode->m_next = nullptr;

	if (m_head == nullptr)
	{
		m_head = tempListNode;
		m_tail = tempListNode;
	}
	else
	{
		tempListNode->m_next = m_head;
		m_head = tempListNode;
	}
}