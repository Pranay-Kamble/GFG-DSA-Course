//
// Created by Pranay Kamble on 26/09/24.
//
#include <iostream>
#define capacity 13

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

int parent(int i) {
    return (i-1)/2;
}

/*
//--------------Naive Approach-----------------
void heapify(int arr[], int size, int i) { //Time Complexity: O(height) = O(logN), Space Complexity: O(height) = O(logN)
    if (i >= size)
        return;

    int smallest = i;
    if (left(i) < size && arr[left(i)] < arr[smallest])
        smallest = left(i);
    if (right(i) < size && arr[right(i)] < arr[smallest])
        smallest = right(i);

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapify(arr, size, smallest);
    }
}*/

void heapify(int arr[], int size, int i) { //Time Complexity: O(height) = O(logN), Space Complexity: O(1)
    if (i >= size)
        return;

    int smallest = i;

    while (i < size) {
        if (left(i) < size && arr[left(i)] < arr[smallest])
            smallest = left(i);
        if (right(i) < size && arr[right(i)] < arr[smallest])
            smallest = right(i);
        if (smallest != i) {
            std::swap(arr[smallest], arr[i]);
            i = smallest;
        }else {
            return;
        }
    }
}

void insertInHeap(int arr[], int &size, int data) {
    if (size >= capacity)
        return ;

    arr[size++] = data;
    int i = size-1;

    while (i > 0 && arr[parent(i)] > arr[i]) {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int extractMin(int heap[], int &size) {
    if (size == 0) return INT_MAX;

    if (size == 1) {
        size--;
        return heap[0];
    }

    int smallest = heap[0];
    std::swap(heap[0], heap[size-1]);
    size--;

    heapify(heap, size, 0);
    return smallest;
}

void print(int arr[], int size) {
    for (int i {}; i<size; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int *arr = new int[capacity];
    int size = 0;

    insertInHeap(arr, size, 100);
    insertInHeap(arr, size, 70);
    insertInHeap(arr, size, 35);
    insertInHeap(arr, size, 60);
    insertInHeap(arr, size, 25);
    insertInHeap(arr, size, 20);
    insertInHeap(arr, size, 30);
    insertInHeap(arr, size, 80);
    insertInHeap(arr, size, 32);
    arr[0] = 31;
    heapify(arr, size,0);
    print(arr,size);
    extractMin(arr, size);
    printf("\n");
    print(arr,size);
    delete []arr;
    return 0;
}