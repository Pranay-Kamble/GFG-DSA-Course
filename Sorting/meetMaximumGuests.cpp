//
// Created by Pranay Kamble on 05/07/24.
//
#include <iostream>

int hoarePartition(int arr[], const int low, const int high) {
    int i{low-1}, j{high+1};
    const int pivot {arr[low]};

    while (true) {
        do { ++i; } while (arr[i] < pivot);
        do { --j; } while (arr[j] > pivot);
        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], const int low, const int high) {
    if (low < high) {
        int p = hoarePartition(arr,low,high);
        quickSort(arr,low,p);
        quickSort(arr,p+1,high);
    }
 }

int meetMaxGuests(int arrival[], int departure[], const int &aSize, const int &dSize) {
    quickSort(arrival,0,aSize-1);
    quickSort(departure,0,dSize-1);

    int maxCount{}, count{},i{0},j{0};

    while (i<aSize && j<dSize) {
        if (arrival[i] < departure[j]) {
            ++count; ++i;
            maxCount = std::max(count, maxCount);
        }
        else if (arrival[i] > departure[j]) {
            --count;++j;
        }
        else {
            ++i; ++j;
        }
    }

    return maxCount;
}

int main() {
    int arrival[] {900,600,700};
    int departure[] {1000,800,730};
    const int aSize {std::size(arrival)};
    const int dSize {std::size(departure)};

    std::cout << "Max Guests possible: " << meetMaxGuests(arrival,departure,aSize,dSize) << std::endl;
    return 0;
}