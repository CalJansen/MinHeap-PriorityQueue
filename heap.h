#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#ifndef HEAP_H
#define HEAP_H
using namespace std;

struct element
{
	int key;
};

class heap
{
	int capacity;
	int size;
	int *H;

public:
	// necessary functions
	heap(int n);
	void Insert(heap heap, int flag, int k);
	void PrintHeap(heap heap);
	void DecreaseKey(heap heap, int flag, int index, int value);
	void BuildHeap(heap heap, int A[], int n);
	int DeleteMin(heap heap, int flag);

	// helper functions
	void MinHeapify(heap heap, int i);
	int Parent(int i);
	int Left(int i);
	int Right(int i);
};

// outside of class functions
heap Initialize(int n);
void swap(int *x, int *y);
#endif