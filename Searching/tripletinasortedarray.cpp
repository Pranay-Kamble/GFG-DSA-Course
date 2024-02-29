#include <iostream>
//We are given a sorted array and a target sum,we need to return true if there is any combination
// in the array which adds up to the target sum, or else return false.

bool two_sum(const int arr[], const int size, const int start, const int search){
    int ptr1 {start};
    int ptr2 {size-1};
    while(ptr1 < ptr2){
        if (arr[ptr1] + arr[ptr2] == search)
            return true;
        else if (arr[ptr1] + arr[ptr2] > search)
            --ptr2;
        else  // if (arr[ptr1] + arr[ptr2] < search)
            ++ptr1;
    }
    return false;
}


/*
---------------Naive Approach--------------------
bool triplet_sum(const  int arr[], const int size, const int sum){
    int current {};             //Time Complexity = O(n^3) , Cubic (Very Bad solution)
    for (int i {}; i<size-3 ; ++i){
        current = 0;
        for (int j {}; j<size-3; ++j){
            if (j == i)
                continue;
            for (int k {}; k<size-3; ++k){
                if (k == j || k == i)
                    continue;
                current += arr[i] + arr[j] + arr[k];
                if (current == sum)
                    return true;
            }
        }
    }

    return false;
}

-------------Efficient Approach--------------*/
bool triplet_sum(const int arr[], const int size, const int search){
    for (int i {}; i<size-2; ++i){   //Time Complexity = O(n^2) , Quadratic
        if ( two_sum(arr, size, i+1, search-arr[i]) )
            return true;
    }
    return false;
}


int main(){
    int arr [] {1,4,6,8,10,45};
    int size {sizeof(arr)/sizeof(arr[0])};
    int search {22};
    std::cout << std::boolalpha << "The result is " << triplet_sum(arr,size,search) << std::endl;
}