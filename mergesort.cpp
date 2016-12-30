// Praktikum_9_mergesort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void printArray(int A[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		cout << A[i] << " ";
	}
	//cout << endl;
}


void copyArray(int dest[], int src[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		dest[i] = src[i];
	}
}


void merge(int left[], int right[], int output[], int size_left, int size_right)
{	
	cout << "left: ";
	printArray(left, size_left);
	cout << "\tright: ";
	printArray(right, size_right);
	int i = 0;
	int j = 0;
	int k = 0;
	while ((i < size_left) && (j < size_right)) {
		if (left[i] < right[j]) {
			output[k] = left[i];
			i++;
			k++;
		}
		else {
			output[k] = right[j];
			j++;
			k++;
		}
	}
	while (i < size_left)
	{
		output[k] = left[i];
		i++;
		k++;
	}
	while (j < size_right)
	{
		output[k] = right[j];
		j++;
		k++;
	}
	cout << "\tmerged: ";
	printArray(output, k);
	cout << endl;
}


void mergeSort(int a_list[], int size)
{
	if (size > 1) {
		int mid = size / 2;
		
		// create the left / right arrays
		int * lefthalf = new int[mid];	
		int * righthalf = new int[size - mid];
		
		// copy the arrays
		copyArray(lefthalf, a_list, mid);
		copyArray(righthalf, &a_list[mid], (size - mid));
		
		// split phase
		mergeSort(lefthalf, mid);
		mergeSort(righthalf, (size - mid));

		merge(lefthalf, righthalf, a_list, mid, size - mid);
		delete[] lefthalf;
		delete[] righthalf;
	}
}


int main()
{
	int arraySize = 0;

	cout << "Wie viele Elemente wollen Sie eingeben?" << endl;
	cin >> arraySize;
	int * arr = new int[arraySize];
	
	cout << "Please enter element# " << endl;
	for (int i = 0; i < arraySize; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, arraySize);
	printArray(arr, arraySize);
	cout << endl;
	system("pause");
	return 0;
}
