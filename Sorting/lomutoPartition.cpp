//
// Created by Pranay Kamble on 03/07/24.
//

#include <iostream>

int lomutoPartition(int arr[], const int low, const int high, const int partition) {
    int i {low-1};
    std::swap(arr[partition], arr[high]);   //Keep the partition index at the end of the array
    const int pivot {arr[high]};

    for (int j {low}; j<=high-1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i],arr[j]);
        }
    }

    std::swap(arr[++i],arr[high]);
    return i;
}

int main() {
    int arr[] {0,1,0,2,3,1,0,1,2,1,3,1,2,0};
    const int low {0};
    const int high {std::size(arr)-1};
    const int partition {3};

    lomutoPartition(arr,low,high,partition);

    for (const int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}