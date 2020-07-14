#include "List.h"
#pragma warning(disable : 4996)

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::List(Node* h, Node* t)
{
	head = h;
	tail = t;
}
// need to change this copy c'tor
List::List(List& other)
{
	

}

List::List(List&& other)
{
	this->head = other.head;
	this->tail = other.tail;
	other.head = nullptr;
	other.head = nullptr;
}

// remember to delete all nodes properly. 
List::~List()
{	

}

void List::addNodeToTail(int n)
{
	Node* tmp = new Node;
	tmp->data = n;
	tmp->next = nullptr;

	if (head == nullptr)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}
}

void List::printList()
{
	Node* curr = head;
	while (curr != nullptr)
	{
		cout << curr->data << "  ";
		curr = curr->next;
	}
	cout << endl;
}

Node* List::getHead()
{
	return head;
}

void List::addNodeToHead(int n)
{
	Node* tmp = new Node;
	tmp->data = n;
	tmp->next = nullptr;

	if (head == nullptr)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
}