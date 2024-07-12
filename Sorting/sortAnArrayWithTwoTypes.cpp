//
// Created by Pranay Kamble on 04/07/24.
//
#include <iostream>


void segregatePositiveAndNegative(int arr[], const int size) {//Similar to Hoare's partition
    int i {-1}, j{size};
    while(true) {
        do {++i;} while(arr[i] < 0);
        do {--j;} while(arr[j] >= 0);

        if (i >= j) return;
        std::swap(arr[i], arr[j]);
    }
}

int main() {
    int arr[] {15,-3,-2,-3,11,2,-35,18,-1,0,1,0,-1};
    const int size{std::size(arr)};

    segregatePositiveAndNegative(arr,size);

    for (int i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}