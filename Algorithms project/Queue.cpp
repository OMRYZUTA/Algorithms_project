#include "Queue.h"
#pragma warning(disable : 4996)

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}

Queue::Queue(Node* h, Node* t)
{
	head = h;
	tail = t;
}

Queue::Queue(Queue& other)
{
	this->head = other.head;
	this->tail = other.tail;
}

Queue::~Queue()
{
}

void Queue::makeEmpty() //לא חושב שיש הבדל מקונסטרקטור
{
	head = nullptr;
	tail = nullptr;
}

bool Queue::isEmpty()
{
	return head == nullptr;
}

void Queue::enqueue(int n)
{
	Node* tmp = new Node;
	tmp->m_data = n;
	tmp->m_next = nullptr;

	if (head == nullptr)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->m_next = tmp;
		tail = tail->m_next;
	}
}

int Queue::dequeue()
{
	int data = head->m_data;
	Node* tmp = head;
	head = head->m_next;
	delete tmp;
	return data;
}
