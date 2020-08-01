#ifndef __MAX_HEAP_H
#define __MAX_HEAP_H
#pragma warning (diable: 4996)
#include <iostream>
#include "HeapElement.h"



class MaxHeap
{
private:
	HeapElement* m_heapArr; // Points to array
	int* m_vertexPlaceInHeap; // vertexPlaceInHeap[v] Saves the index of vertex v in heapArr; 
	int m_maxSize; // Max size of Heap
	int m_heapSize; // Current size of Heap
	int m_allocated; // 1 if Heap allocated memory
	int Left(int i_node);
	int Right(int i_node);
	int Parent(int i_node);
	void FixHeap(int i_node); // Fixes the heap that has node as root
	void BuildHeap(HeapElement i_A[], int i_size); // Builds heap
public:
	MaxHeap(int i_max);
	MaxHeap(HeapElement i_A[], int i_size); // Converts an array which contains n numbers into heap
	~MaxHeap();
	int DeleteMax(); // Delete max which is found in the root of the heap, and fix heap
//	void Insert(HeapElement item); לא בטוח שהפונקציה הזו בכלל בשימוש בתכנית. יש לבדוק!!! // Add a new leaf for item, and swap upwards until item is in its correct position
	bool IsEmpty();
	void IncreaseKey(int i_place, int i_newKey);
	int Max(); // Returns the max element in the max heap == its root
    void swap(HeapElement& i_a, HeapElement& i_b);
    void printHeap();
};
#endif // __MAX_HEAP_H
