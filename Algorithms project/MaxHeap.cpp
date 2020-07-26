#include "MaxHeap.h"
#pragma warning(disable : 4996)


MaxHeap::MaxHeap(int max)
{
	heapArr = new HeapElement[max];
	maxSize = max; 
	heapSize = 0; 
	allocated = 1; 
}

MaxHeap::MaxHeap(HeapElement A[], int size)
{
	heapSize = maxSize = size;

	heapArr = A; // Assign array A to data pointer
	allocated = 0; // Memory not allocated by heap

	BuildHeap(A, size); // Builds heap
}

void MaxHeap::BuildHeap(HeapElement A[], int size)
{
	// Builds heap according to Floyd algorithm
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}

MaxHeap::~MaxHeap()
{
	if (allocated)
		delete[] heapArr;
	heapArr = nullptr;
}

int MaxHeap::Parent(int node)
{
	return (node - 1) / 2;
}

int MaxHeap::Left(int node)
{
	return (2 * node + 1);
}

int MaxHeap::Right(int node)
{
	return (2 * node + 2);
}

void MaxHeap::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && ((heapArr[left].getkey()) > (heapArr[node]).getkey()))
	{
		max = left;
	}
	else
	{
		max = node;
	}

	if ((right < heapSize) && ((heapArr[right].getkey()) > (heapArr[max]).getkey()))
	{
		max = right;
	}

	// Swap values if necessary and continue fixing the heap towards the leaves
	if (max != node)
	{
		swap(heapArr[node], heapArr[max]);
		FixHeap(max);
	}
}

int MaxHeap::DeleteMax()
{
	if (heapSize < 1)
	{
		cout << "Error: EMPTY HEAP\n";
		exit(1);
	}

	int max = heapArr[0].getdata();
	heapSize--;
	heapArr[0] = heapArr[heapSize];
	FixHeap(0);
	return max;
}

void MaxHeap::Insert(HeapElement item)
{
	if (heapSize == maxSize)
	{
		cout << "Error: HEAP FULL\n";
		exit(1);
	}

	int i = heapSize;
	heapSize++;

	while ((i > 0) && ((heapArr[Parent(i)].getkey()) < (item.getkey())))
	{
		heapArr[i] = heapArr[Parent(i)];
		i = Parent(i);
	}

	heapArr[i] = item;
}

bool MaxHeap::IsEmpty()
{
	if (heapSize < 1)
		return 1;
	else
		return 0;
}

void MaxHeap::IncreaseKey(int place, int newKey)
{
	if (heapArr[place].getkey() > newKey)
	{ 
		cout << "newKey is smaller than current key\n";
		return;
    }

	heapArr[place].setkey(newKey);
	while ((place > 0) && ((heapArr[Parent(place)].getkey()) < (heapArr[place].getkey())))
	{
		swap(heapArr[place], heapArr[Parent(place)]);
		place = Parent(place);
	}

}

int MaxHeap::Max()
{
	return heapArr[0].getdata();
}

void MaxHeap::swap(HeapElement& a, HeapElement& b)
{
	HeapElement temp;

	temp = a; 
	a = b;    
	b = temp; 
}