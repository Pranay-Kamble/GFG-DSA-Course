//
// Created by Pranay Kamble on 30/06/24.
//
#include <iostream>

/*int countInversions(int arr[], int size) {
    int count {};
    for (int i{}; i<size-1; ++i) {
        for (int j{i+1}; j<size; ++j) {
            if (arr[i] > arr[j])
                ++count;
        }
    }
    return count;
}*/

int countAndMerge (int arr[], const int low, const int mid, const int high) {
    int count {};
    const int size1 {mid-low+1}, size2 {high-mid};
    int arr1[size1], arr2[size2];

    for (int i {}; i<size1; ++i) {
        arr1[i] = arr[low+i];
    }

    for (int i {}; i<size2; ++i) {
        arr2[i] = arr[mid+1+i];
    }

    int i {}, j{};

    while (i<size1 && j<size2) {
        if (arr1[i] <= arr2[j]) {
            arr[low+i+j] = arr1[i];
            ++i;
        } else {
            arr[low+i+j] = arr2[j];
            count += size1 - i; //If element in first array is bigger than an element in second array,
            ++j;// then the element in the second array will form a inversion pair with all the next
        }        //elements in the first array. So we add (size1 - i) to the count.
    }

    while (i<size1) {
        arr[low + i + j] = arr1[i];
        ++i;
    }
    while (j<size2) {
        arr[low+i+j] = arr2[j];
        ++j;
    }

    return count;
}

int countInversions(int arr[],const int low,const int high) {
    const int mid {low + ((high-low)/2)};
    int count {};

    if (low < high) {
        count += countInversions(arr,low,mid);
        count += countInversions(arr,mid+1,high);
        count += countAndMerge(arr,low,mid,high);
    }

    return count;
}

int main() {
    int arr[] {5,4,3,2,1};
    const int size {std::size(arr)};
    std::cout << "The no of inversions are: "  << countInversions(arr,0,size-1) << std::endl;
    return 0;
}