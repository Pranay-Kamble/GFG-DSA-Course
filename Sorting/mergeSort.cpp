//
// Created by Pranay Kamble on 28/06/24.
//
#include <iostream>

void merge(int arr[], const int low, const int mid, const int high) {
    const int size1 {mid - low + 1}, size2 {high - mid};
    int arr1[size1], arr2[size2];

    for (int i {}; i<size1; ++i)
        arr1[i] = arr[low+i];

    for (int i {}; i<size2; ++i)
        arr2[i] = arr[mid+1+i];

    int i {0}, j {0};
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {    //Equal to sign ensures the stability
            arr[low+i+j] = arr1[i];
            ++i;
        }
        else {
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

void mergeSort(int arr[], const int low, const int high) {
    const int mid {low + ((high - low)/2)};

    if (low < high) {  // If minimum two elements are present, then condition is true
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr, low,mid,high);
    }
}

int main() {
    int arr[] {10,5,30,15,324,2,5,3,2,1,5,66,75,3,2,7};
    const int low {0}, high {std::size(arr)-1};
    mergeSort(arr,low,high);

    for (int i: arr) {
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    return 0;
}