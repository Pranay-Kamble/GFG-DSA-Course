//
// Created by Pranay Kamble on 26/06/24.
//
#include <iostream>
/*------------Naive Approach--------------TC-> Theta(n^2)
void bubbleSort(int arr[], const int size) {
    for (int i = 0; i<size - 1;  ++i) {
        for (int j = 0; j<size-i-1; ++j) {
            if (arr[j] > arr[j+1])
                swap(arr, j, j+1);
        }
    }
}
-----------Optimized Approach------------TC -> O(n^2), becomes linear when array is sorted*/
void bubbleSort(int arr[], const int size) {
    for (int i = 0 ; i< size-1; ++i) {
        bool isSwapped = false;
        for (int j = 0 ;  j<size-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                isSwapped = true;
                std::swap(arr[j],arr[j+1]);
            }
        }
        //Will be true if no swapping is done before, if no swapping is done it means array is sorted
        if (isSwapped == false)
            return;
    }
}

int main() {
    int arr[10] {97,56,3,2,6,7,2,73,5,3};
    bubbleSort(arr,sizeof(arr)/sizeof(arr[0]));

    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}