/*
* Title: Sorting and Algorithm Efficiency
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 1
* Description: description of your code
*/
#include "sorting.h"
#include <iostream>
#include <ctime>

void performanceAnalysis(int type) {

    clock_t startTime;
    double duration = 0;
    for(int size = 4000; size < 48001; size+=4000) {
        int* arr1 = new int[size];
        int* arr2 = new int[size];
        int* arr3 = new int[size];
        long long  moveCount = 0;
        long long compCount = 0;

        createAscendingArrays(arr1, arr2, arr3, size);
        cout<<"Size time compCount moveCount"<<endl;

        if(type == 1) {
            //Bubble
            startTime = clock();
            bubbleSort(arr1, size, compCount, moveCount);
            duration = double(clock() - startTime);

            cout<<size<<" "<<duration<<"  "<<compCount<<"       "<<moveCount<<endl;
        }else if(type == 2){
            startTime = clock();
            mergeSort(arr1, size, compCount, moveCount);
            duration = double(clock() - startTime);

            cout<<size<<" "<<duration<<" "<<compCount<<"    "<<moveCount<<endl;
        }else {
            startTime = clock();
            quickSort(arr1, size, compCount, moveCount);
            duration = double(clock() - startTime);

            cout<<size<<" "<<duration<<" "<<compCount<<"       "<<moveCount<<endl;
        }

        delete [] arr1, arr2, arr3;
    }
}

int main() {

	int arr[16] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,
33, 26 };

	const int size = 16;
    long long compCount = 0;
    long long moveCount = 0;

	cout << "BUBBLE" << endl;
	displayArray(arr, size);
	bubbleSort(arr, size, compCount, moveCount);
    cout<<"Key Comparisons: "<<compCount<<endl;
    cout<<"Data moves: "<<moveCount<<endl;
	displayArray(arr, size);

    cout<<endl;

	cout << "MERGE" << endl;
	int arr2[16] = { 40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,
33, 26 };
	displayArray(arr2, size);
	mergeSort(arr2, size, compCount, moveCount);
    cout<<"Key Comparisons: "<<compCount<<endl;
    cout<<"Data moves: "<<moveCount<<endl;
	displayArray(arr2, size);

    cout<<endl;

	cout << "QUICK" << endl;
	int arr3[16] = { 40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,
33, 26 };
	displayArray(arr3, size);
	quickSort(arr3, size, compCount, moveCount);
    cout<<"Key Comparisons: "<<compCount<<endl;
    cout<<"Data moves: "<<moveCount<<endl;
	displayArray(arr3, size);


}


