//
// Created by Pranay Kamble on 29/06/24.
//
#include <iostream>

/*--------------My Solution----------> Works if only positive integers are present
 *void intersection(int arr1[],const int size1, int arr2[],const  int size2) {
    int i {}, j{};
    int previous {-1}; //What if -1 is also present in the array, it is the only issue in this code

    while (i<size1 && j<size2) {
        if (arr1[i] == arr2[j]) {
            if (arr1[i] != previous) {
                std::cout << arr1[i] << " ";
                previous = arr1[i];
            }
            ++i; ++j;
        }
        else if (arr1[i] <= arr2[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }
}

------------------------Efficient Approach-----------*/
void intersection(int arr1[],const int size1, int arr2[],const int size2) {
    int i {}, j{};
    while(i<size1 && j<size2) {
        if (i > 0 && arr1[i] == arr1[i-1]) {   //Time Complextiy = O(size1 + size2)
            ++i;
            continue;
        }

        if (arr1[i] < arr2[j])
            ++i;
        else if (arr1[i] > arr2[j])
            ++j;
        else {
            std::cout << arr1[i] << " ";
            ++i; ++j;
        }
    }
}

int main() {
    int arr1[] {2,20,20,40,60};
    int arr2[] {10,20,20,20};
    intersection(arr1, std::size(arr1), arr2, std::size(arr2));

    return 0;
}