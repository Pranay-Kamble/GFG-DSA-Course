#include <iostream>
/*----------My Approach(Naive)-----------
int majority(int arr[], int size){   //Time Complexity = O(n*n)
    int count = 1;
    for (int i{0}; i<size-1; ++i){
        int ele {arr[i]};
        for (int j{i+1}; j<size; ++j){
            if(ele == arr[j]){
                ++count;
            }
            if (count > size/2){
                return j;
            }
        }
        count = 1;
    }
    return -1;
}
------------Efficient Approach---------*/

int majority(int arr[], int size){
    int count{1},res{};              //Moore's Voting Algorithm
    for(int i{}; i<size; ++i){
        if (arr[i] == arr[res])     //This loop finds the possible majority element by checking its probabilty in 
            ++count;                // being the possible answer 
        else
            --count;
        if(count == 0){
            res = i;
            count = 1;
        }
    }


    count = 0;
    for(int i{}; i<size; ++i){     //This part of the program is just to verify that the possible element is 
        if (arr[i] == arr[res])    // really a majority element or not
             ++count;
    }
    if(count <= size/2)        //This part just counts the number of occurrences of the possible majority element,
        return -1;             // and checks if its count is greater than size/2
    
    return count;
}

int main(){
    int arr[] {8,7,6,8,6,6,6,6};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout  <<majority(arr,size) << std::endl;
}

