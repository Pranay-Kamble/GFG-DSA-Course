//
// Created by Pranay Kamble on 01/10/24.
//
#include <iostream>
#include <queue>


void merge(int arr[], int low, int mid, int high) {
    int size1 {mid-low+1}, size2 {high-mid};
    int arr1[size1], arr2[size2];

    for (int i{}; i<size1; ++i)
        arr1[i] = arr[low+i];

    for (int i{}; i<size2; ++i) {
        arr2[i] = arr[mid+i+1];
    }

    int i {}, j{};

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[low+i+j] = arr1[i];
            i++;
        }else {
            arr[low+i+j] = arr2[j];
            ++j;
        }
    }

    while (i < size1) {
        arr[low+i+j] = arr1[i];
        ++i;
    }
    while (j < size2) {
        arr[low+i+j] = arr2[j];
        ++j;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int mid {low + (high-low)/2};
    mergeSort(arr,low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

/*
void kLargestElements(int arr[], int size, int k) { //Time Complexity: O(N * logN), Space Complexity: O(N)
    mergeSort(arr,0,size-1);
    for (int i{size-1}, j = 0; j<k; ++j, --i) {
        std::cout << arr[i] << ' ';
    }
}*/

/*
void kLargestElements(int arr[], int size, int k) { //Time Complexity: O(N + (K * logN)), Space Complexity: O(N)
    std::priority_queue<int> pQueue;  //using a max heap
    for (int i{}; i<size; ++i) {
        pQueue.push(arr[i]);
    }

    for (int i{}; i<k; ++i) {
        std::cout << pQueue.top() << " ";
        pQueue.pop();
    }
    std::cout << std::endl;
}*/

void kLargestElements(int arr[], int size, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pQueue;//Time Complexity: O(k + (N-k)LogN), Auxiliary Space: O(k)
    for (int i{}; i<k; ++i) { //Push first k elements
        pQueue.push(arr[i]);
    }

    for (int i{k}; i<size; ++i) { //Remove elements from heap if they are smaller
        if (arr[i] > pQueue.top()) {
            pQueue.pop();
            pQueue.push(arr[i]);
        }
    }

    for (int i{}; i<k; ++i) { //Prints the remaining elements
        std::cout << pQueue.top() << " ";
        pQueue.pop();
    }
}


int main() {
    int arr[] {5,10,15,20,8};
    int size {std::size(arr)};
    int k {2};
    printf("The %d largest elements are: ", k);
    kLargestElements(arr,size,k);
    printf("\n");
    return 0;
}