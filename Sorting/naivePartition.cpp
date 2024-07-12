//
// Created by Pranay Kamble on 01/07/24.
//
#include <iostream>

/*void partition(int arr[], const int size, int part) {
    int i {0};

    while (i<size) {
        if (((arr[i] > arr[part]) && part > i) ||
            ((arr[i] <= arr[part]) && i > part)) {
            std::swap (arr[i], arr[part]);
            part = i;
        }
        ++i;
    }
}*/


void naivePartition(int arr[],const int low, const int high,const int part) {
    int temp[high-low+1];
    int filled {0};

    for (int i {low}; i<=high; ++i) {
        if (arr[i] <= arr[part]) {
            temp[filled++] = arr[i];
        }
    }

    for (int i {low}; i<=high; ++i) {
        if (arr[i] > arr[part]) {
            temp[filled++] = arr[i];
        }
    }

    for (int i {low}; i<=high; ++i) {
        arr[i] = temp[i-low];
    }
}

int main() {
    int arr[] {5,13,6,12,11,8,9};
    const int size {std::size(arr)};

    naivePartition(arr,0,6,6);

    for (int i {}; i<size; ++i) {
        std::cout << arr[i] << " ";
    }
}