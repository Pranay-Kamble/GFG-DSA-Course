#include <iostream>

/*
--------------Naive Approach---------------
bool issorted(int arr[], int size){  //Idea~>All the elements on the right of an element should be greater 
    for(int i{}; i<size-1;++i){      //      than the current element
        for(int j{i+1}; j < size; ++j){
            if(arr[j] < arr[i]){                //Time Complexity = O(n*n)
                return false;
            }
        }
    }
    return true;
}

--------------Efficient Approach------------*/
bool issorted(int arr[], int size){//Idea~>Only the next element should be greater than the current element
    for (int i{}; i<size-1; ++i){
        if(arr[i+1] >= arr[i]){     //Time Complexity = O(n)
            continue;
        }
        return false;
    }
    return true;
}

int main(){
    int arr[] {10,10,20};
    std::cout << std::boolalpha << issorted(arr,2);
}