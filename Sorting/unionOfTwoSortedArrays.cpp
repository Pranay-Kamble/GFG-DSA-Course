//
// Created by Pranay Kamble on 29/06/24.
//
#include <iostream>

void unionOfSortedArrays(int arr1[], const int size1, int arr2[], const int size2) {
    int i {}, j{};

    while (i<size1 && j<size2) {
        if (i > 0 && arr1[i-1] == arr1[i]) {
            ++i; continue;
        }
        if (j > 0 && arr2[j-1] == arr2[j]) {
            ++j; continue;
        }

        if (arr1[i] < arr2[j]) {
            std::cout << arr1[i] << " ";
            ++i;
        }
        else if (arr1[i] > arr2[j]) {
            std::cout << arr2[j] << " ";
            ++j;
        }
        else {
            std::cout << arr1[i] << " ";
            ++i; ++j;
        }
    }

    while (i<size1) {
        if (i > 0 && arr1[i-1] != arr1[i])
            std::cout << arr1[i] << " ";
        ++i;
    }

    while (j<size2) {
        if (j > 0 && arr2[j-1] != arr2[j])
            std::cout << arr2[j] << " ";
        ++j;
    }
}


int main() {
    int arr1[] {10,20,20};
    int arr2[] {5,20,40,40};

    unionOfSortedArrays(arr1, std::size(arr1), arr2, std::size(arr2));
}