//
// Created by Pranay Kamble on 04/07/24.
//
#include <iostream>

/*
--------------------Naive Solution-----------------

int hoarePartition(int arr[], const int low, const int high) {
    int i {low-1}, j {high+1};
    const int pivot {arr[low]};

    while (true) {
        do {++i;}
        while(arr[i] < pivot);

        do {--j;}
        while(arr[j] > pivot);

        if (i >= j) return j;

        std::swap(arr[i],arr[j]);
    }
}

void quickSort(int arr[], const int low, const int high) {
    if (low < high) {
        int partition = hoarePartition(arr,low,high);
        quickSort(arr,low,partition);
        quickSort(arr,partition+1,high);
    }
}

//Time Complexity = O(n log(n)) {Average Case} , O(n^2) {Worst Case}
//Space Complexity = O(n) ,For recursive calls of quickSort
void kthSmallest(int arr[], const int size, const int k) {
    quickSort(arr,0,size-1);

    int copy {k-1};
    int i {1};
    while (copy > 0 && i<size) {
        if (arr[i] > arr[i-1])
            --copy;
        ++i;
    }
    std::cout << k << " smallest element is " << arr[i-1] << std::endl;
}


------------------Efficient Approach--------------*/
int lomutoPartition(int arr[],const int low,const int high) {
    int i {low-1};
    const int pivot {arr[high]};

    for (int j {low}; j<=high-1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i+1],arr[high]);
    return i+1;
}
//Time Complexity = Same as quickSort, but this is faster as solution can be found on first run itself
//Space Complexity = O(1)
int kthSmallest(int arr[], int low, int high, const int k) {
    int p {};
    while (low<=high) {
        p = lomutoPartition(arr,low,high);

        if (p == k-1)
            return arr[p];

        if (p > k-1)
            high = p-1;
        else
            low = p+1;
    }
    return -1;
}

int main() {
    int arr[] {10,4,5,8,11,6,26};
    const int size {std::size(arr)};

    std::cout << kthSmallest(arr,0,size-1,5) << std::endl;
}