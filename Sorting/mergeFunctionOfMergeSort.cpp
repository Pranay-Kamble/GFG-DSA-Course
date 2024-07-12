//
// Created by Pranay Kamble on 28/06/24.
//

#include <iostream>

/*We are given an array with indexes low, mid and high. The elements are sorted from low to mid and mid+1 to high. We
need to sort it overall from low to high indexes.
Conditions-

*Low is not always 0, meaning subarray can also start from between the array.
*/

void merge(int arr[], const int low, const int mid, const int high) {
    const int size1 = mid + 1;
    const int size2 = high - mid; //Time Complexity = Theta(size)
    int arr1 [size1], arr2[size2];  //Space Complexity = Theta(size)

    for (int i = 0; i< mid+1; ++i) {
        arr1[i] = arr[low+i]; //i+low ensures the correct index, if low is not zero
    }

    for (int i = mid+1; i<high+1; ++i) {
        arr2[i-(mid+1)] = arr[low+i];
    }

    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[i+j+low] = arr1[i];
            ++i;
        }
        else {
            arr[i+j+low] = arr2[j];
            ++j;
        }
    }

    while (i < size1) {
        arr[low+i+j] = arr1[i];
        ++i;
    }
    while (j < size2) {
        arr[low+i+j] = arr2[j];
        ++j;
    }
}

/*----------My Approach------------

//Time Complexity -> O(size^2) , Space Complexity -> Theta(1)

void specialMerge(int arr[], const int low, const int mid, const int high) {
    int i = low, j = mid+1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            ++i;
        else {
            int index = j-1, temp = arr[j];

            while (index >= 0 && arr[index] > temp) {
                arr[index+1] = arr[index];
                --index;
            }
            arr[index + 1] = temp;
            ++j;
        }
    }
}*/

int main() {
    int arr[] {10,20,40,20,30};
    const int low = 0, mid = 2, high = 4;

    merge(arr,low,mid,high);

    for (int i: arr) {
        std::cout << i << " " ;
    }
}