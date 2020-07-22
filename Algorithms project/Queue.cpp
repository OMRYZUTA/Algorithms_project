#include "Queue.h"
#pragma warning(disable : 4996)

Queue::Queue()
{
	m_head = nullptr;
	m_tail = nullptr;
}

Queue::Queue(Node* i_head, Node* i_tail)// do we need this? delete later
{
	m_head = i_head;
	m_tail = i_tail;
}

Queue::Queue(Queue& i_otherQueue) // we need to fix this Queue
{
	if (i_otherQueue.isEmpty())
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	else
	{
		Node* tempOldQueueNode = i_otherQueue.m_head;
		Node* builderQueueNode = new Node;
		// initializing head
		builderQueueNode->setData(tempOldQueueNode->getData());
		m_head = builderQueueNode;
		tempOldQueueNode = tempOldQueueNode->getNext();
		while (tempOldQueueNode)
		{
			builderQueueNode->setNextNode(new Node);
			builderQueueNode = builderQueueNode->getNext();
			builderQueueNode->setData(tempOldQueueNode->getData());
			tempOldQueueNode = tempOldQueueNode->getNext();
		}
		m_tail = builderQueueNode;
	}
}

Queue::~Queue()
{
	Node* tempQueueNode = m_head;
	Node* nextQueueNode = m_head->getNext();
	while (nextQueueNode) // run through all the list
	{
		delete tempQueueNode;
		tempQueueNode = nextQueueNode;
		nextQueueNode = tempQueueNode->getNext();
	}
	m_head = nullptr; // to avoid double deletes bugs
	m_tail = nullptr;
}

void Queue::makeEmpty() 
{
	m_head = nullptr;
	m_tail = nullptr;
}

bool Queue::isEmpty()
{
	return m_head == nullptr;
}

void Queue::enqueue(int i_data)
{
	Node* tempNode = new Node;
	tempNode->setData(i_data);
	tempNode->setNextNode(nullptr);

	if (m_head == nullptr)
	{
		m_head = tempNode;
		m_tail = tempNode;
	}
	else
	{
		m_tail->setNextNode( tempNode);
		m_tail = m_tail->getNext();
	}
}

int Queue::dequeue()
{
	int data = m_head->getData();
	Node* tmp = m_head;
	m_head = m_head->getNext();
	delete tmp;
	return data;
}
