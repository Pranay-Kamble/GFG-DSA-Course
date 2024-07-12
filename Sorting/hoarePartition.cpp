//
// Created by Pranay Kamble on 03/07/24.
//
#include <iostream>


int hoarePartition(int arr[],const int low, const int high, const int partition) {
    int i {low-1}, j {high+1};
    std::swap (arr[low],arr[partition]); //Time Complexity = O(n) , Space Complexity = O(1)
    const int pivot {arr[low]};

    while (true) {
        do { ++i; }
        while (arr[i] < pivot);

        do { --j; }
        while (arr[j] > pivot);

        if (i >= j) return j;

        std::swap(arr[i],arr[j]);
    }
}


int main() {
    int arr[]{10, 24, 3, 20, 3, 20, 4, 3};
    const int low{};
    const int high{std::size(arr) - 1};
    const int partition{6};

    hoarePartition(arr, low, high, partition);
    for (const int i: arr) {
        std::cout << i << " ";
    }

    return 0;
}
