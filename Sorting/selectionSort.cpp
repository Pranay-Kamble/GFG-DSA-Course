//
// Created by Pranay Kamble on 26/06/24.
//

#include <iostream>

void selectionSort(int arr[], const int size) {  //Time Complexity -> Ɵ(n^2)
    for (int i = 0; i<size-1; ++i) {   //Space Complexity -> Ɵ(1)
        int minIndex {i};

        for (int j {i+1}; j<size; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i],arr[minIndex]);
    }
}


int main() {
    int arr[] {10,5,8,20,2,18 };
    selectionSort(arr, sizeof(arr)/sizeof(arr[0]));

    for (int i : arr) {
        std::cout << i << ' ';
    }

    return 0;
}