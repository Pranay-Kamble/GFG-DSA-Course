//
// Created by Pranay Kamble on 03/07/24.
//

#include <iostream>

int lomutoPartition (int arr[], const int low, const int high) {
    int i {low-1};
    const int pivot {arr[high]};

    for (int j {low}; j<=high-1;  ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap (arr[i],arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);  //Fixing pivot to its correct position
    return i+1;
}

void quickSort(int arr[], const int low, const int high) {
    if (low < high) { //True if minimum two elements are present
        const int partition = lomutoPartition(arr, low, high);
        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1, high);
    }
}

int main() {
    int arr[] {2,6,3,7,6,32,22,7,55,4,3,433,6,4};
    const int low {0};
    const int high {std::size(arr) - 1};
    quickSort(arr,low,high);

    for(int i: arr) {
        std::cout << i << " ";
    }

    return 0;
}