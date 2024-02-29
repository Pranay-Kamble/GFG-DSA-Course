#include <iostream>

// We are given a sorted input array and a target sum, we need to find whether the sum of
// any two elements in the array is equal to the target sum or not and return a boolean value.


bool binarysearch(int arr[], int search, int low , int high){ 
    int mid {(low+high)/2};   //Time Complexity for binary search = O(log n)
    while(low<=high){
        if (arr[mid] == search)
            return true;
        if (arr[mid] > search)
            high = mid-1;
        else
            low = mid+1;
        mid = (low+high)/2;
    }
    return false;
}
/*---------Naive Solution---------
bool two_sum(int arr[], int size, int sum){  //Time Complexity = O(n * log n)
    for (int i {}; i<size; ++i){
        if (binarysearch(arr, sum-arr[i] ,0,size-1))
            return true;
    }
    return false;
}
----------Efficient Solution------*/ 
// if the largest and smallest elements (sorted array) add up and give a sum larger than target, 
// then we can ignore the largest element safely, if the largest and smallest element add up and
// give a smaller value than target , then we can ignore the smallest element safely

bool two_sum(int arr[], int size, int sum){
    int ptr1 {}, ptr2{size-1};   //Time Complexity = O(n) , Linear
    int compare {};
    while (ptr1 < ptr2){
        compare = arr[ptr1] + arr[ptr2];
        if (compare == sum)
            return true;

        if (compare < sum)  // If sum of largest and smallest is less than target, we can ignore
            ++ptr1;         // the smallest element
        else  //compare > sum
            --ptr2;
    }
    return false;
}

int main(){
    int arr[] {4,8,9,11,12,20,30};
    int size {sizeof(arr)/sizeof(arr[0])};
    int sum {22};
    std::cout << std::boolalpha << "Result: " << two_sum(arr, size, sum) << std::endl;
    return 0; 
}