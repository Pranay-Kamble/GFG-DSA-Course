//
// Created by Pranay Kamble on 26/09/24.
//
#include <iostream>
class MinHeap {
private:
    int *arr;
    int size = 0;
    int capacity = 0;
public:
    MinHeap(int capacity) {
        this->arr = new int[capacity];
        this->capacity = capacity;
    }

    ~MinHeap() {
        delete this->arr;
    }

    int left(int i) {
        return this->arr[2*i + 1];
    }
    int right(int i) {
        return this->arr[2*i + 2];
    }
    int parent(int i) {
        return this->arr[(i-1)/2];
    }

    /*//-----------Recursive MinHeapify Implementation--------------
     void heapify(int i) {
        if (i >= this->size)
            return;

        int smallest = i;
        if (left(i) < size && arr[left(i)] < arr[smallest])
            smallest = left(i);
        if (right(i) < size && arr[right(i)] < arr[smallest])
            smallest = right(i);

        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }*/

    //-------------Iterative MinHeap Implementation-------------------
    void heapify(int i) {
        if (i >= this->size)
            return;

        int smallest = i;
        while (i < size) {
            if (left(i) < size && arr[i] > arr[smallest])
                smallest = left(i);
            if (right(i) < size && arr[i] > arr[smallest])
                smallest = right(i);

            if (smallest != i) {
                std::swap(arr[i], arr[smallest]);
                i = smallest;
            }else {
                return;
            }
        }
    }


    int extractMin() {
        if (size == 0) return INT_MAX;

        if (size == 1) {
            size--;
            return this->arr[0];
        }

        std::swap(arr[0], arr[size-1]);
        size--;
        heapify(0);
        return arr[size];
    }

    void decreaseKey(int i, int newVal) {
        if (i >= this->size)
            return;

        this->arr[i] = newVal;
        while (i > 0 && parent(i) > arr[i]) {
            std::swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        if (i >= size) return;

        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void insertIntoHeap(int val) {
        if (size >= capacity) {
            printf("Not empty\n");
            return;
        }

        arr[size++] = val;
        int i = size-1;
        while (i>0 && arr[parent(i)] > arr[i]) {
            std::swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
};