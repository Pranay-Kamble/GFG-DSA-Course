#include <iostream>
// You are given an unsorted array and you have to return the peak element which is the element 
// greater than both of its neighbouring elements, if it is first or last element then we need to
// check for only one of the neighbouring element.

/*
-----------Naive Solution------------
int peakelement(int arr[], int size){  //Time Complexity = O(n) , Linear
    if (size == 1)
        return arr[0];

    if (arr[0] > arr[1])
        return arr[0];
    
    for (int i{1}; i<size-1; ++i){
        if ( (arr[i] >= arr[i-1]) && (arr[i] >= arr[i+1]) )
            return arr[i];
    }
    if (arr[size-1] > arr[size-2])
        return arr[size-1]; 

    return -1;
}
-------------Efficient Solution----------*/
int peakelement(int arr[], int size){
    int low {}, high {size-1}, mid {(low+high)/2};  //Time Complexity = O(log n)
    while (low <= high){
        if ( (mid == 0 || arr[mid] >= arr[mid-1]) && (mid == size-1 || arr[mid] >= arr[mid+1]) )
            return arr[mid];
        if (mid > 0 && arr[mid-1] >= arr[mid])
            high = mid-1;
        else
            low = mid+1; 
        mid = (low+high)/2;
    }  //There will always be a peak element on the half which is greater than the mid element
    return -1;
}

int main(){
    int arr[] {80,70,60};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout <<"The peak element of the array is " << peakelement(arr,size) << std::endl;
    return 0;
}