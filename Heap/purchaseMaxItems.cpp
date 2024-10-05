//
// Created by Pranay Kamble on 01/10/24.
//
#include <iostream>


int left(int i) {
    return (2*i) + 1;
}

int right(int i) {
    return (2*i) + 2;
}

int parent(int i) {
    return (i-1)/2;
}

void minHeapify(int arr[], int size, int i) {
    if (i >= size) return;

    int smallest = i;

    while (i < size) {
        if (left(i) < size && arr[left(i)] < arr[smallest]) {
            smallest = left(i);
        }

        if (right(i) < size && arr[right(i)] < arr[smallest]) {
            smallest = right(i);
        }

        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);
            i = smallest;
        }else {
            return;
        }
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
    minHeapify(arr,size,arr[0]);
    return arr[size+1];
}

void decreaseKey(int arr[], int &size, int i, int newVal) {
    if (i >= size) return;

    arr[i] = newVal;

    while (i > 0 && arr[parent(i)] > arr[i]) {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void deleteKey(int arr[], int &size, int i) {
    decreaseKey(arr,size,i, INT_MIN);
    extractMin(arr, size);
}

void buildHeap(int arr[], int size) {
    for (int i {parent(size-1)}; i >= 0; --i) {
        minHeapify(arr, size,i);
    }
}

/*
int purchaseMaxItems(int arr[], int size, int money) { //Time Complexity: O(N*logN), Space Complexity: O(1), if modification
    std::sort(arr, arr+size);                                                       //                 O(N), if no modification
    int sum = 0, count = 0;
    for (int i {}; i<size; ++i) {
        if (sum+arr[i] < money) {
            sum += arr[i];
            ++count;
        }else
            return count;
    }
    return count;
}*/



int purchaseMaxItems(int arr[], int size, int money) { //Time Complexity: O(n) + O(res * logN) ~ O(res * logN)
    buildHeap(arr, size);                              //Space Complexity: O(1), if modification is allowed
    int sum = 0;                                       //                  O(n), if modification is not allowed
    int count = 0;

    while (true) {
        int top = extractMin(arr,size);
        if (sum+top > money) return count;

        sum += top;
        count++;
    }
}


int main() {
    int arr[] {1,12,5,111,200};
    int size {std::size(arr)};

    std::cout << "Max Purchase Count: " << purchaseMaxItems(arr, size,10) << std::endl;

    return 0;
}