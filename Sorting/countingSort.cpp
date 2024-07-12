//
// Created by Pranay Kamble on 06/07/24.
//
#include <iostream>

/*
----------------Naive Implementation-----------------
void countingSort(int arr[], const int size, const int k) {
    int counts[k];   //Time Complexity = Theta(n + k) , but is unstable
    for (int i {}; i<k; ++i)
        counts[i] = 0;

    for (int i {0}; i<size; ++i) {
        counts[arr[i]]++;
    }

    int index{};
    for (int i {}; i<k; ++i) {
        for (int j{}; j<counts[i]; ++j) {
            arr[index++] = i;
        }
    }
}
---------------Efficient Approach--------------------*/
void countingSort(int arr[], const int size, const int k) { //Time Complexity = Theta(n + k), Space = Theta(n+k), Stable Algorithm
    int count[k];
    for (int i {}; i<k; ++i) { //Initialise the array to zeroes
        count[i] = 0;
    }
    for (int i{}; i<size; ++i) { //Store the number of occurrences of the array elements in its indexes
        count[arr[i]]++;
    }
    for (int i{1}; i<k; ++i) { //Modify slightly to store the number which represents the number
        count[i] = count[i-1] + count[i];   //of elements less than or equal to that element(index).
    }
    int output[size];
    for (int i{size-1}; i>=0; --i) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for (int i{};i<size;++i) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] {1,4,4,1,0,1};
    const int size {std::size(arr)};
    const int k {6};
    countingSort(arr,size,k);

    for (const int i: arr)
        std::cout << i << " ";

    return 0;
}