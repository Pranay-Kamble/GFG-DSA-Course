//
// Created by Pranay Kamble on 04/07/24.
//
#include <iostream>

/*void segregateZeroesOnesTwos(int arr[], const int size) {
    int i {-1};
    const int pivot {1};

    for (int j {0}; j<size; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i],arr[j]);
        }
    }
}*/

void segregateZeroesOnesTwos(int arr[], const int size) {
    int low {0}, mid {0}, high{size-1};
    while (mid <= high) {
        if (arr[mid] == 0)
            std::swap(arr[mid++], arr[low++]);
        else if (arr[mid] == 1)
            ++mid;
        else //arr[j] == 2
            std::swap(arr[mid],arr[high--]);
    }
}

int main() {
    int arr[] {0,1,2,1,1,2};
    const int size {std::size(arr)};

    segregateZeroesOnesTwos(arr, size);

    for (int i: arr)
        std::cout << i << ' ';
    return 0;
}