#include <iostream>

/*----------Naive Approach----------
int maxsum(int arr[], int size){ //Time Complexity = Theta(n*n) 
    int max{arr[0]};
    int current_sum {};

    for (int i{}; i<size-1; ++i){

        for(int j{i}; j<size;++j){
            current_sum += arr[j];
            max = std::max(current_sum,max);
        }

        current_sum = 0;
    }

    return max;
}

-----------Efficient Approach---------*/
int maxsum(int arr[], int size){  //Time Complexity = Theta(n), Linear
    int max {arr[0]};
    int sum{};
    for (int i{}; i<size; ++i){
        sum += arr[i];             
        sum = std::max(sum,arr[i]);  //this decides whether the previous subarray should be continued or not
        max = std::max(sum,max);        
    }
    return max;
}

int main(){
    int arr[] {-3,8,-2,4,-5,6};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout << maxsum(arr,size) << std::endl;
    std::cout <<"Hello World!";
}