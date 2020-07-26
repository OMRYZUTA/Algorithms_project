#ifndef __MAX_HEAP_H
#define __MAX_HEAP_H
#pragma warning (diable: 4996)
#include <iostream>
#include "HeapElement.h"



class MaxHeap
{
private:
	HeapElement* heapArr; // Points to array
	int maxSize; // Max size of Heap
	int heapSize; // Current size of Heap
	int allocated; // 1 if Heap allocated memory
	int Left(int node);
	int Right(int node);
	int Parent(int node);
	void FixHeap(int node); // Fixes the heap that has node as root
	void BuildHeap(HeapElement A[], int size); // Builds heap
public:
	MaxHeap(int max);
	MaxHeap(HeapElement A[], int size); // Converts an array which contains n numbers into heap
	~MaxHeap();
	int DeleteMax(); // Delete max which is found in the root of the heap, and fix heap
	void Insert(HeapElement item); // Add a new leaf for item, and swap upwards until item is in its correct position
	bool IsEmpty();
	void IncreaseKey(int place, int newKey);
	int Max(); // Returns the max element in the max heap == its root
    void swap(HeapElement& a, HeapElement& b);
};
#endif // __MAX_HEAP_H
