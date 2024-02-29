#include <iostream>
/*
------------Naive Appraoch-------------
int onesinbinarysortedarray(int arr[], int size, int search){ 
    int first_index {};
    for (int i{}; i<size; ++i){
        if (arr[i] == 1){}
            first_index = i;
            break;
    }
    
    return size-first_index;
}
 ///Just find the first occurrence of 1, and then subtract the first occurrence from size
----------------Efficient Approach-------------*/
int onesinbinarysortedarray(int arr[], int size, int search = 1){
    int low{};
    int high{size-1};   //Time Complexity = O(logn)
    int mid{(low+high)/2};
    int first_index {-1};

    while(low <= high){
        if (arr[mid] == search){
            if (mid == 0 || arr[mid-1] != search){
                first_index = mid;
                break;
            }
            high = mid-1;
            mid = (low+high)/2;
        }
        else{//if arr[mid] is not 1 then it is a zero, so we need to check for right half only
            low = mid +1;
            mid = (low+high)/2;
        }
    }  
    if (first_index == -1)
        return 0;
    return (size-first_index);
}

int main(){
    int arr[] {0,0,1,1,1,1,1};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout << "The number of '1's in the sorted binary array is " << onesinbinarysortedarray(arr,size);
}