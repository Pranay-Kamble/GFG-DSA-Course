//
// Created by Pranay Kamble on 28/09/24.
//
#include <iostream>
#include <queue>



/*
void merge(std::vector<int> &arr, int low, int mid, int high) {
    int size1 {mid-low+1}, size2 {high-mid};
    int arr1[size1], arr2[size2];

    for (int i{}; i<size1; ++i) {
        arr1[i] = arr[low+i];
    }

    for (int i{}; i<size2; ++i) {
        arr2[i] = arr[mid+i+1];
    }

    int i {0}, j {0};

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[low+i+j] = arr1[i];
            ++i;
        }else {
            arr[low+i+j] = arr2[j];
            ++j;
        }
    }

    while (i < size1) {
        arr[low+i+j] = arr1[i];
        ++i;
    }
    while (j<size2) {
        arr[low+i+j] = arr2[j];
        ++j;
    }
}

void mergeSort(std::vector<int> &arr, int low, int high) {
    if (low >= high)
        return;

    int mid = (low) + (high-low)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr, low, mid, high);
}

//--------------Naive Approach-------------------
void sortKSortedArray(std::vector<int> &vector, int k) { //Time Complexity: O(N * logN), Space Complexity: O(N)
    mergeSort(vector,0,vector.size()-1);
}
*/


void sortKSortedArray(std::vector<int> &vector, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pQueue;


    for (int i {}; i<=k; ++i) {
        pQueue.push(vector[i]);
    }
    int index = 0;

    for (int i{k+1};i<vector.size(); ++i) {
        vector[index++] = pQueue.top();
        pQueue.pop();
        pQueue.push(vector[i]);
    }

    while (!pQueue.empty()) {
        vector[index++] = pQueue.top();
        pQueue.pop();
    }
}


int main() {
    std::vector<int> vector {9,8,7,19,18};
    int k = 2; //Any element in the index after sorting can only be in the range of index -> i-k to i+k
    sortKSortedArray(vector, k);
    for (int i: vector)
        printf("%d ", i);

    return 0;
}