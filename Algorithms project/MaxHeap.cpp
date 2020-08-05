#include "MaxHeap.h"
#pragma warning(disable : 4996)


MaxHeap::MaxHeap(int i_max)
{
	m_heapArr = new HeapElement[i_max];
	m_vertexPlaceInHeap = new int[i_max];
	m_maxSize = i_max; 
	m_heapSize = 0; 
	m_allocated = 1; 
}

MaxHeap::MaxHeap(HeapElement i_A[], int i_size)
{
	m_heapSize = m_maxSize = i_size;

	m_heapArr = i_A; // Assign array A to data pointer
	m_allocated = 0; // Memory not allocated by heap

	m_vertexPlaceInHeap = new int[m_heapSize];
	for (int i = 0; i < m_heapSize; i++)
	{
		if (i_A[i].getdata() >= m_maxSize)
		{
			cout << "Error! data is out of bounds" << endl;
		}
		// each data field in A[0]...A[n] is unique, so we will fill properly each spot in the vertexPlaceInHeap array
		m_vertexPlaceInHeap[i_A[i].getdata()] = i;//saves the current index of vertex A[i]  
	}

	BuildHeap(i_A, i_size); // Builds heap
}

void MaxHeap::BuildHeap(HeapElement i_A[], int i_size)
{
	// Builds heap according to Floyd algorithm
	for (int i = i_size / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}

MaxHeap::~MaxHeap()
{
	if (m_allocated)
		delete[] m_heapArr;
	m_heapArr = nullptr;

	delete[] m_vertexPlaceInHeap;
	m_vertexPlaceInHeap = nullptr;
}

int MaxHeap::Parent(int i_node)
{
	return (i_node - 1) / 2;
}

int MaxHeap::Left(int i_node)
{
	return (2 * i_node + 1);
}

int MaxHeap::Right(int i_node)
{
	return (2 * i_node + 2);
}

void MaxHeap::FixHeap(int i_node)
{
	int max;
	int left = Left(i_node);
	int right = Right(i_node);

	if ((left < m_heapSize) && ((m_heapArr[left].getkey()) > (m_heapArr[i_node]).getkey()))
	{
		max = left;
	}
	else
	{
		max = i_node;
	}

	if ((right < m_heapSize) && ((m_heapArr[right].getkey()) > (m_heapArr[max]).getkey()))
	{
		max = right;
	}

	// Swap values if necessary and continue fixing the heap towards the leaves
	if (max != i_node)
	{
		m_vertexPlaceInHeap[m_heapArr[i_node].getdata()] = max;
		m_vertexPlaceInHeap[m_heapArr[max].getdata()] = i_node;
		swap(m_heapArr[i_node], m_heapArr[max]);
		FixHeap(max);
	}
}

int MaxHeap::DeleteMax()
{
	if (m_heapSize < 1)
	{
		cout << "Error: EMPTY HEAP\n";
		exit(1);
	}

	int max = m_heapArr[0].getdata();

	m_vertexPlaceInHeap[m_heapArr[0].getdata()] = -1; //value in heapArr[0] is going to be removed.
	m_heapSize--;
	m_vertexPlaceInHeap[m_heapArr[m_heapSize].getdata()] = 0; //לא בטוח שצריך
	m_heapArr[0] = m_heapArr[m_heapSize];
	FixHeap(0);
	return max;
}





bool MaxHeap::IsEmpty()
{
	if (m_heapSize < 1)
		return 1;
	else
		return 0;
}

void MaxHeap::IncreaseKey(int place, int newKey)
{
	// place is the vertex "name" (1 to n), placeInHeap is the index of this vertex in the heap.
	int placeInHeap = m_vertexPlaceInHeap[place]; 

	if (m_heapArr[placeInHeap].getkey() > newKey)
	{ 
		cout << "newKey is smaller than current key\n";
		return;
    }

	m_heapArr[placeInHeap].setkey(newKey);
	// as long as the parent key is bigger than the child, and the index is legal
	while ((placeInHeap > 0) && ((m_heapArr[Parent(placeInHeap)].getkey()) < (m_heapArr[placeInHeap].getkey())))
	{

		m_vertexPlaceInHeap[m_heapArr[placeInHeap].getdata()] = Parent(placeInHeap);
		m_vertexPlaceInHeap[m_heapArr[Parent(placeInHeap)].getdata()] = placeInHeap;
		swap(m_heapArr[placeInHeap], m_heapArr[Parent(placeInHeap)]);
		placeInHeap = Parent(placeInHeap);
	}

}

int MaxHeap::Max()
{
	return m_heapArr[0].getdata();
}

void MaxHeap::swap(HeapElement& a, HeapElement& b)
{
	HeapElement temp;

	temp = a; 
	a = b;    
	b = temp; 
}

void MaxHeap::printHeap()
{
	for (int i = 0; i < m_heapSize; i++)
	{
		cout << "heap Element key: " << m_heapArr[i].getkey() << " heap Element data " << m_heapArr[i].getdata();
		cout << endl;
	}
}
