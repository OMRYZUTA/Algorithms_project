#include "MaxHeap.h"
#pragma warning(disable : 4996)


MaxHeap::MaxHeap(int max)//
{
	heapArr = new HeapElement[max];
	vertexPlaceInHeap = new int[max];
	maxSize = max; 
	heapSize = 0; 
	allocated = 1; 
}

MaxHeap::MaxHeap(HeapElement A[], int size)
{
	heapSize = maxSize = size;

	heapArr = A; // Assign array A to data pointer
	allocated = 0; // Memory not allocated by heap

	vertexPlaceInHeap = new int[heapSize];
	for (int i = 0; i < heapSize; i++)
	{
		// each data field in A[0]...A[n] is unique, so we will fill properly each spot in the vertexPlaceInHeap array
		vertexPlaceInHeap[A[i].getdata()] = i;//saves the current index of vertex A[i]  
	}

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

	delete[] vertexPlaceInHeap;
	vertexPlaceInHeap = nullptr;
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
		vertexPlaceInHeap[heapArr[node].getdata()] = max;
		vertexPlaceInHeap[heapArr[max].getdata()] = node;
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

	vertexPlaceInHeap[heapArr[0].getdata()] = -1; //value in heapArr[0] is going to be removed.
	heapSize--;
	vertexPlaceInHeap[heapArr[heapSize].getdata()] = 0; //לא בטוח שצריך
	heapArr[0] = heapArr[heapSize];
	FixHeap(0);
	return max;
}


/*void MaxHeap::Insert(HeapElement item) // לא בטוח שהפונקציה הזו בכלל בשימוש בתכנית. יש לבדוק!!!
{
	if (heapSize == maxSize)
	{
		cout << "Error: HEAP FULL\n";
		exit(1);
	}

	int i = heapSize;
	heapSize++;
	// כנראה הפונקציה לא בשימוש, אבל אם כן צריך לחשוב איך מטפלים כאן במערך עזר כשהערימה גדלה

	while ((i > 0) && ((heapArr[Parent(i)].getkey()) < (item.getkey())))
	{
		vertexPlaceInHeap[heapArr[Parent(i)].getdata()] = i;
		heapArr[i] = heapArr[Parent(i)];
		i = Parent(i);
	}

	vertexPlaceInHeap[item.getdata()] = i;
	heapArr[i] = item;
}*/


bool MaxHeap::IsEmpty()
{
	if (heapSize < 1)
		return 1;
	else
		return 0;
}

void MaxHeap::IncreaseKey(int place, int newKey)
{
	// place is the vertex "name" (1 to n), placeInHeap is the index of this vertex in the heap.
	int placeInHeap = vertexPlaceInHeap[place]; 

	if (heapArr[placeInHeap].getkey() > newKey)
	{ 
		cout << "newKey is smaller than current key\n";
		return;
    }

	heapArr[placeInHeap].setkey(newKey);
	while ((placeInHeap > 0) && ((heapArr[Parent(placeInHeap)].getkey()) < (heapArr[placeInHeap].getkey())))
	{
		vertexPlaceInHeap[heapArr[placeInHeap].getdata()] = Parent(placeInHeap);
		vertexPlaceInHeap[heapArr[Parent(placeInHeap)].getdata()] = placeInHeap;
		swap(heapArr[placeInHeap], heapArr[Parent(placeInHeap)]);
		placeInHeap = Parent(placeInHeap);
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