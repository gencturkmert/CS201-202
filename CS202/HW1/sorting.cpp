/*
* Title: Sorting and Algorithm Efficiency
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 1
* Description: Main.cpp
*/

#include "sorting.h"

void bubbleSort(int* arr, const int size, long long& compCount, long long& moveCount) {

    bool sorted = false;
    compCount = 0;
    moveCount = 0;

    for (int i = 1; (i < size) && !sorted; ++i) {
        sorted = true;
        for (int j = 0; j < size - i; ++j) {
            compCount += 1;
            if (arr[j] > arr[j+1]) {
                moveCount += 3;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = false; // signal exchange
            }
        }
    }


    return;

}

#include "sorting.h"
void mergeSort(int* arr, const int size, long long& compCount, long long& moveCount) {

    compCount = 0;
    moveCount = 0;
    mergesort(arr, 0, size - 1, size, compCount, moveCount);



}
void quickSort(int* arr, const int size, long long& compCount, long long& moveCount) {
    compCount = 0;
    moveCount = 0;

    quicksort(arr, 0, size - 1, compCount, moveCount);

}

void mergesort(int* theArray, int first, int last,int size, long long& compCount, long long& moveCount) {

    if (first < last) {

        int mid = (first + last) / 2; 	// index of midpoint

        mergesort(theArray, first, mid,size,compCount,moveCount);

        mergesort(theArray, mid + 1, last,size, compCount, moveCount);

        // merge the two halves
        merge(theArray, first, mid, last,size, compCount, moveCount);
    }
}

void merge(int* theArray, int first, int mid, int last, const int size, long long& compCount, long long& moveCount) {

    int* tempArray = new int[size]; 	// temporary array

    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1] < theArray[first2]) {
            tempArray[index] = theArray[first1];
            ++first1;
            moveCount++;
        }
        else {
            tempArray[index] = theArray[first2];
            ++first2;
            moveCount++;
        }

        compCount++;
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        moveCount++;
        tempArray[index] = theArray[first1];
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = theArray[first2];
        moveCount++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        theArray[index] = tempArray[index];
        moveCount++;
    }
    delete [] tempArray;

}

void quicksort(int* theArray, int first, int last, long long& compCount, long long& moveCount) {
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex,compCount,moveCount);

        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex - 1,compCount,moveCount);
        quicksort(theArray, pivotIndex + 1, last,compCount,moveCount);
    }
}

void partition(int* theArray, int first, int last,
    int& pivotIndex, long long& compCount, long long& moveCount) {
    // Precondition: theArray[first..last] is an array; first <= last.
    // Postcondition: Partitions theArray[first..last] such that:
    //   S1 = theArray[first..pivotIndex-1] < pivot
    //   theArray[pivotIndex] == pivot
    //   S2 = theArray[pivotIndex+1..last] >= pivot

    int pivot = theArray[first]; // the first element
    moveCount++;
    
// initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

     // move one item at a time until unknown region is empty
    for (; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot
        compCount++;
        // move item from unknown to proper region
        if (theArray[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            int tmp = theArray[firstUnknown];
            theArray[firstUnknown] = theArray[lastS1];
            theArray[lastS1] = tmp;
            moveCount += 3;
        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    int temp;
    temp = theArray[first];
    theArray[first] = theArray[lastS1];
    theArray[lastS1] = temp;

    moveCount += 3;
    pivotIndex = lastS1;
    
}

void displayArray(const int* arr, const int size) {
    using namespace std;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "," ;
    }
    cout << endl;

}

void createRandomArrays(int *arr1, int *arr2, int *arr3, const int size){

    for(int j = 0;j< size;j++) {
        arr1[j] = rand() % 50000;
    }
    for(int j = 0; j<size;j++) {
        arr2[j]=arr1[j];
        arr3[j] = arr1[j];
    }
}

void createAscendingArrays(int *arr1, int *arr2, int *arr3, const int size){

    arr1[0] = 0;

    for(int i = 1;i<size;i++) {
        arr1[i] = arr1[i-1] + (rand() %1000);
    }

    for(int j = 0; j<size;j++) {
        arr2[j]=arr1[j];
        arr3[j] = arr1[j];
    }
}

void createDescendingArrays(int *arr1, int *arr2, int *arr3, const int size){
    arr1[0] = 100000;

    for(int i = 1;i<size;i++) {
        arr1[i] = arr1[i-1] - (rand() % 1000);
    }

    for(int j = 0; j<size;j++) {
        arr2[j]=arr1[j];
        arr3[j] = arr1[j];
    }
}


