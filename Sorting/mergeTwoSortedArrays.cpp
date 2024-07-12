//
// Created by Pranay Kamble on 27/06/24.
//
#include <iostream>

/*-----------Naive Solution---------------
void insertionSort(int arr[],const int size) {
    for (int i = 1; i<size; ++i) {
        const int temp = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            --j;
        }

        arr[j+1] = temp;
    }
}

void mergeTwoSorted(int arr1[], const int size1, int arr2[], const int size2) { //Time Complexity = Theta(n^2)
    int temp[size1 + size2];
    for (int i = 0; i<size1; ++i) {
        temp[i] = arr1[i];
    }

    for (int i = size1; i<size1+size2; ++i) {
        temp[i] = arr2[i-size1];
    }
    insertionSort(temp,size1+size2);

    for (int i : temp) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

--------------Efficient Approach-------------*/
void mergeTwoSorted(int arr1[], const int size1, int arr2[2], const int size2) {
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {  //Equal to sign ensures stability of the algorithm, arr1 is given more priority than arr2
            std::cout << arr1[j] << " ";
            ++i;
        } else {
            std::cout << arr2[i] << " ";
            ++j;
        }
    }

    while (i < size1) {
        std::cout << arr1[i] << " ";
        ++i;
    }
    while (j < size2) {
        std::cout << arr2[j] << " ";
        ++j;
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] {1,5,6,7,32,55,60,69,77,89,99};
    int arr2[] {12,32,44,45,66,77,81,656,777};
    mergeTwoSorted(arr1,std::size(arr1),arr2, std::size(arr2));
    return 0;
}