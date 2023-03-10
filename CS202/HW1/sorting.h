/*
* Title: Sorting and Algorithm Efficiency
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 1
* Description: Main.cpp
#include "sorting.h"
*/
#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <stdlib.h>

using namespace std;
void bubbleSort(int* arr, const int size, long long& compCount, long long& moveCount);
void mergeSort(int* arr, const int size, long long& compCount, long long& moveCount);
void quickSort(int* arr, const int size, long long& compCount, long long& moveCount);

void displayArray(const int* arr, const int size);
void createRandomArrays(int *arr1, int *arr2, int *arr3, const int size);
void createAscendingArrays(int *arr1, int *arr2, int *arr3, const int size);
void createDescendingArrays(int *arr1, int *arr2, int *arr3, const int size);


	void mergesort(int* theArray, int first, int last, int size, long long& compCount, long long& moveCount);
	void merge(int* theArray, int first, int mid, int last, const int size, long long& compCount, long long& moveCount);

	void quicksort(int* theArray, int first, int last, long long& compCount, long long& moveCount);
	void partition(int* theArray, int first, int last, int& pivotIndex, long long& compCount, long long& moveCount);


#endif
