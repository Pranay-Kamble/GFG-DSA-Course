#include <iostream>
/*
-------------Naive Solution-1 --------------
int repeatedelement(int arr[], int size){
    for (int i {}; i<size-1 ; ++i){    //Time Complexity = O(n^2)
        for (int j {i+1}; j<size; ++j){
            if (arr[i] == arr[j])
                return arr[i];
        }
    }
}

-----------Naive Solution-2 --------------
 First sort the array using the best sorting algorithm (Since i dont know sorting except bubble sort for now)
 then iterate through array till n-1, if arr[i] == arr[i+1],
 then return arr[i]


----------Better Solution----------------

 -//Using another boolean array to mark the presence of a number which has occurred
 -// if it is present again then it would have already been marked as true the first time
 -// then we can return the result


int repeatedelement(int arr[], int size){
    bool store [size-1];            // Time Complexity = O(n)
    for (int i {}; i<size-2; ++i){  // Space Complexity = O(n)
        store[i] = false;
    }

    for (int i {}; i<size; ++i){
        if (store[arr[i]])
            return arr[i];

        store[arr[i]] = true;
    }
    return -1;
}

----------Efficient Solution-------------*/   
// Hare and tortoise method (Popular linked list algorithm)

int repeatedelement(int arr[], int size){   //Time Complexity = O(n)
    int fast{arr[0]+1}, slow{arr[0]+1};     //Auxiliary Space = O(1)

    do {                       
        slow = arr[slow]+1;         // No need to add ones everywhere if it is given                                 
        fast = arr[arr[fast]+1]+1;  // that zero is not present in the array
    } 
    while (slow != fast);

    fast = arr[0]+1;

    while (slow != fast){
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }

    return fast-1;
}


int main(){
    int arr[] {0,0,0,0,0,0,0,0,1};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout << "The repeating element is " << repeatedelement(arr,size) << std::endl;
    return 0;
}