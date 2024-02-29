#include <iostream>

//Only works for sorted array

int linearsearch(int arr[], int size, int search){
    for (int i{}; i<size; ++i){
        if (arr[i] > search)
            return -1;
        if (arr[i] == search)
            return i;
    }
    return -1;
}

int binarysearch(int arr[], int size, int search){
    int low {0};
    int high {size-1};
    int mid {(low+high)/2};

    while(low <= high){
        if (arr[mid] == search)
            return mid;
        
        if (arr[mid] > search){
            high = mid-1;
            mid = (low + high) / 2;  //mid = low + ((high - low) / 2) --> Use to avoid overflow 
        }                            //                                   on large data sets

        else { //(arr[mid] < search)
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }

    return -1;
}

int main(){
    int arr[] {10,20,30,40,50,60};
    int size {sizeof(arr)/sizeof(arr[0])};
    int search {20};
    std::cout << "The Index of " << search <<": " << binarysearch(arr,size,search) << '\n';
    return 0;
}