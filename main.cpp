#include "heap.h"
#include "util.h"
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <cstdlib>

/**
* Name: Callan Jansen
* Date: 3/18/19
* Description: CSE310 Project 1- Building a MinHeap.
*/


using namespace std;

int main()
{
	char filename[] = "HEAPinput.txt";
	ifstream fileInput;	// used to read from file
	int heapCreated = 1;	// "boolean" value, if heapCreated == 1, no heap has been created yet
	heap testHeap = NULL;
	char c;	// holds command input from command line
	int i, v, f;	// used to hold int values from command line
	int counter = 0;

	while (1) {
		c = nextCommand(&i, &v, &f);
		c = toupper(c);

		switch (c) {
		case 'S':
			printf("COMMAND: %c.\n", c);
			exit(0);
		case 'C':
			printf("COMMAND: %c %d.\n", c, i);
			testHeap = Initialize(i);
			heapCreated = 2;	// heap has been created
			break;
		case 'R':
			printf("COMMAND: %c.\n", c);
			fileInput.open(filename);
			if (!fileInput.is_open())
			{
				cout << "There was a problem opening file HEAPinput.txt for reading.\n";
			}

			int inputArray[33];
			counter = 0;

			while (!fileInput.eof())	// until reaching the end of the file, add to array
			{
				fileInput >> inputArray[counter];
				counter++;
			}

			fileInput.close();
			if (counter != 0)
			{
				testHeap = Initialize(counter);	
				testHeap.BuildHeap(testHeap, inputArray, counter);	// build heap from the existing array
				heapCreated = 2;
			}
			break;
		case 'W':
			printf("COMMAND: %c.\n", c);
			if (heapCreated == 2)
				testHeap.PrintHeap(testHeap);
			else
				cout << "Sorry!!! It cannot be done. Please initialize the heap first.";
			break;
		case 'I':
			printf("COMMAND: %c %d %d.\n", c, f, v);
			if (heapCreated == 2)
				testHeap.Insert(testHeap, f, v);
			else
				cout << "Sorry!!! It cannot be done. Please initialize the heap first.";
			break;
		case 'D':
			printf("COMMAND: %c %d.\n", c, f);
			if (heapCreated == 2)
				testHeap.DeleteMin(testHeap, f);
			else
				cout << "Sorry!!! It cannot be done. Please initialize the heap first.";
			break;
		case 'K':
			printf("COMMAND: %c %d %d %d.\n", c, f, i, v);
			if (heapCreated == 2)
				testHeap.DecreaseKey(testHeap, f, i - 1, v);
			else
				cout << "Sorry!!! It cannot be done. Please initialize the heap first.";
			break;
		default:
			break;
		}
	}
	exit(0);
}