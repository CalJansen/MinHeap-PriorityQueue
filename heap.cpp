#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "heap.h"
using namespace std;

heap::heap(int n)	// constructor
{
	capacity = n;
	size = 0;
	H = new int[capacity];
}

heap Initialize(int n) // this function calls the constructor
{
	heap *newHeap = new heap(n);
	return *newHeap;
}

void heap::PrintHeap(heap heap)	// prints the capacity, size, and contents of the current heap
{
	cout << "The capacity is " << capacity << ".\n";
	cout << "Size is " << size << ".\n";
	for (int i = 0; i < size; i++)
	{
		cout << H[i] << "\n";
	}
}

void heap::Insert(heap heap, int flag, int k) // inserts a new value into the existing heap
{
	if (size == capacity)	// if heap is full, need to dynamically allocate more memory
	{
		int oldCapacity = capacity;
		int newCapacity = oldCapacity * 2;
		int* temp = new int[newCapacity];
		std::copy(H, H + 5, temp);
		delete H;
		H = temp;
		capacity = newCapacity;
	}

	if (flag == 2)	// if flag is 2, print before and after
	{
		PrintHeap(heap);
		size++;
		int i = size - 1;
		H[i] = std::numeric_limits<int>::max();
		DecreaseKey(heap, 1, i, k);
		PrintHeap(heap);
		return;
	}

	size++;
	int i = size - 1;
	H[i] = std::numeric_limits<int>::max();
	DecreaseKey(heap, 1, i, k);
}

int heap::DeleteMin(heap heap, int flag)	// returns the smallest value and maintains heap property
{
	if (size < 1)
	{
		cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.";
		return -1;
	}

	if (flag == 2)	// print before and after if flag = 2
	{
		PrintHeap(heap);
		int min = H[0];
		H[0] = H[size - 1];
		size--;
		MinHeapify(heap, 0);
		PrintHeap(heap);
		return min;
	}

	int min = H[0];
	H[0] = H[size - 1];
	size--;
	MinHeapify(heap, 0);
	return min;
}

void heap::BuildHeap(heap heap, int A[], int arraySize)	// turns an existing array into a MinHeap
{
	capacity = arraySize;
	size = arraySize;
	for (int i = 0; i < arraySize; i++)
	{
		H[i] = A[i];
	}

	for (int i = capacity / 2; i >= 0; i--)
	{
		MinHeapify(heap, i);
	}
}

void heap::MinHeapify(heap heap, int index)	// helper function for a few methods that helps maintain heap property
{
	int left = Left(index);
	int right = Right(index);
	int smallest = index;
	if (left < size && H[left] < H[index])
	{
		smallest = left;
	}
	if (right < size && H[right] < H[smallest])
	{
		smallest = right;
	}
	if (smallest != index)
	{
		swap(&H[index], &H[smallest]);
		MinHeapify(heap, smallest);
	}
}

void heap::DecreaseKey(heap heap, int flag, int index, int key)	// changes the value of an existing member of the heap and readjusts
{
	if (size < 1)
	{
		cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.";
		return;
	}

	if (H[index] < key)
	{
		cout << key << " cannot be larger than the current value in the heap at index "
			<< index + 1 << ". Hence this operation cannot be completed.\n";
		return;
	}
	if (flag == 2)
	{
		PrintHeap(heap);
		H[index] = key;
		while (index != 0 && H[Parent(index)] > H[index])
		{
			swap(&H[index], &H[Parent(index)]);
			index = Parent(index);
		}
		PrintHeap(heap);
		return;
	}

	H[index] = key;
	while (index != 0 && H[Parent(index)] > H[index])
	{
		swap(&H[index], &H[Parent(index)]);
		index = Parent(index);
	}
}

void swap(int *x, int *y)	// helper function
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int heap::Parent(int n)	// helper function
{
	return (n / 2);
}

int heap::Left(int n)	// helper function
{
	return (2 * n + 1);
}

int heap::Right(int n)	// helper function
{
	return (2 * n + 2);
}