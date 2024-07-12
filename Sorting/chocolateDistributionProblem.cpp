//
// Created by Pranay Kamble on 04/07/24.
//
#include <iostream>

int hoarePartition(int arr[], const int low, const int high) {
    int i {low-1}, j{high+1};
    const int pivot {arr[low]};

    while(true) {
        do{ ++i; }
        while (arr[i] < pivot);

        do { --j; }
        while (arr[j] > pivot);

        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], const int low, const int high) {
    if (low < high) {
        int partition = hoarePartition(arr, low, high);
        quickSort(arr,low,partition);
        quickSort(arr,partition+1,high);
    }
}

int chocolateDistributionProblem(int arr[], const int size,int m) {
    quickSort(arr,0,size-1);
    int minIndex {-1};
    int minSum {INT_MAX};
    --m;

    for (int i{}; i+m<size; ++i) {
        if (arr[i+m] - arr[i] < minSum) {
            minSum = arr[i+m] - arr[i];
            minIndex = i;
        }
    }

    std::cout << "We will choose elements " ;
    for (int i = minIndex; i <= minIndex + m; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return minSum;
}

int main() {
    int arr[] {3, 4, 1, 9, 56, 7, 9, 12};
    const int size {std::size(arr)};
    const int m {5};
    const int diff {chocolateDistributionProblem(arr,size,m)};
    std::cout << "The minimum difference is " << diff << std::endl;
}