//
// Created by Pranay Kamble on 27/09/24.
//
#include <iostream>

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

int parent(int i) {
    return (i-1)/2;
}

void maxHeapify(int arr[], int size, int index) {
    if (index >= size) return;

    int largest = index;

    if (left(index) < size && arr[left(index)] > arr[largest])
        largest = left(index);
    if (right(index) < size && arr[right(index)] > arr[largest])
        largest = right(index);

    if (largest != index) {
        std::swap(arr[largest], arr[index]);
        maxHeapify(arr, size, largest);
    }
}

void buildHeap(int arr[], int size) {
    for (int i {parent(size-1)}; i>=0; --i) {
        maxHeapify(arr, size, i);
    }
}


void heapSort(int arr[], int size) {
    buildHeap(arr, size);

    for (int i {size-1}; i >= 1; --i) {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void print(int arr[], int size) {
    for (int i {}; i<size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] {2,4,3,1,3,5,3,2,5,6,4,32};
    const int size = sizeof(arr)/sizeof(arr[0]);

    print(arr,size);
    heapSort(arr, size);
    print(arr,size);

    return 0;
}