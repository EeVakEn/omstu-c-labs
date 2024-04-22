#include <iostream>
#include "matrix_operations.h"

using namespace std;

int* shiftArray(int arr[], int size, int shiftSize) {
    int* removedElements = new int[shiftSize]; 
    for (int i = 0; i < shiftSize; ++i) {
        removedElements[i] = arr[size - shiftSize + i];
    }
    for (int i = size - 1; i >= shiftSize; --i) {
        arr[i] = arr[i - shiftSize];
    }
    for (int i = 0; i < shiftSize; ++i) {
        arr[i] = 0;
    }
    return removedElements; 
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}