//
// Created by Pranay Kamble on 04/07/24.
//
#include <iostream>

int hoarePartition(int arr[], const int low, const int high) {
    int i{low-1}, j{high+1};
    const int pivot {arr[low]};

    while(true) {
        do {++i;}
        while(arr[i] < pivot);
        do {--j;}
        while(arr[j] > pivot);

        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], const int low, const int high) {
    if (low < high) {
        int partition {hoarePartition(arr,low,high)};
        quickSort(arr,low,partition);
        quickSort(arr,partition+1,high);
    }
}

int minimumDifference(int arr[], const int low, const int high) {
    quickSort(arr,low,high);

    int min {INT_MAX};
    for (int i{1}; i <= high; ++i) {
        if (arr[i] - arr[i-1] < min)
            min = arr[i]-arr[i-1];
    }
    return min;
}


int main() {
    int arr[]{10};
    const int low {0};
    const int high {std::size(arr) - 1};
    std::cout << "The minimum difference is " << minimumDifference(arr,low,high) << std::endl;

    return 0;
}