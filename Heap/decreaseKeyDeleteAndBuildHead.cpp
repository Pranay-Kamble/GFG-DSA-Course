//
// Created by Pranay Kamble on 26/09/24.
//
#include <iostream>
#define capacity 100

int left(int i) {
    return 2*i +1;
}

int right(int i) {
    return 2*i + 2;
}

int parent(int i) {
    return (i-1)/2;
}

void heapify(int arr[], int size, int i) {
    if (size == 0) return;

    int smallest = i;
    while (i < size) {
        if (left(i) < size && arr[smallest] > arr[left(i)])
            smallest = left(i);
        if (right(i) < size && arr[smallest] > arr[right(i)])
            smallest = right(i);

        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);
            i = smallest;
        }else
            return;
    }
}

void decreaseKey(int arr[], int size, int i, int replace) { //Time Complexity: O(logN), Space Complexity: O(1)
    if (i >= size)
        return;

    arr[i] = replace;

    while (i > 0 && arr[parent(i)] > arr[i]) {
        std::swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

int extractMin(int arr[], int &size) {
    if (size == 0) return INT_MAX;

    if (size == 1) {
        size--;
        return arr[0];
    }

    std::swap(arr[0], arr[size-1]);
    size--;
    heapify(arr, size, 0);
    return arr[size];
}



void deleteKey(int arr[], int &size, int i) {
    if (i >= size) return;
    decreaseKey(arr, size, i, INT_MIN);
    extractMin(arr, size);
}

void insertInHeap(int arr[], int &size, int data) {
    if (size > capacity) {
        printf("Heap Overflow.\n");
        return;
    }

    arr[size++] = data;
    int i = size-1;

    if (arr[parent(i)] < arr[i])
        return;

    while (i > 0 && arr[parent(i)] > arr[i]) {
        std::swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void buildHeap(int arr[], int size) { //Time Complexity: O(n), looks like N*logN, but by tight analysis it is O(n)
    for (int i {parent(size-1)}; i>=0; --i) {
        heapify(arr,size, i);
    }
}

void print(int arr[], int size) {
    for (int i {}; i<size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int *arr = new int[capacity] {10,56,43,22,17,54,23};
    int size = 7;
    // insertInHeap(arr, size, 10);
    // insertInHeap(arr, size, 20);
    // insertInHeap(arr, size, 30);
    // insertInHeap(arr, size, 40);
    // insertInHeap(arr, size, 50);
    // insertInHeap(arr, size, 35);
    // insertInHeap(arr, size, 38);
    // insertInHeap(arr, size, 45);
    print(arr,size);
    buildHeap(arr,size);
    print(arr,size);
    delete []arr;
    return 0;
}