//
// Created by Pranay Kamble on 26/09/24.
//
#include <iostream>

class MinHeap {
    int *arr, capacity, size;

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    ~MinHeap() {
        delete this->arr;
    }

    int left(int i) {
        return 2*i + 1;
    }
    int right(int i) {
        return 2*i + 2;
    }
    int parent(int i) {
        return (i-1)/2;
    }

    void print() {
        for (int i {}; i<size; ++i) {
            std::cout << this->arr[i] << " ";
        }
    }
    void insert(int data);

};

void MinHeap::insert(int data) {
    if (size >= capacity) return;

    this->arr[size] = data;
    int i = size++;

    if (arr[i] >= arr[parent(i)])
        return;

    while (i>0 && arr[parent(i)] > arr[i]) {
        std::swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

int main() {
    MinHeap heap(9);
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(40);
    heap.insert(50);
    heap.insert(100);
    heap.insert(25);
    heap.insert(45);
    heap.insert(0);

    heap.print();

    return 0;
}