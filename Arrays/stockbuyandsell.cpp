#include <iostream>

unsigned int stockbuyandsell(int arr[], int size){
    unsigned int profit {};
    for(int i{1}; i<size; ++i){
        if(arr[i] > arr[i-1]){
            profit += arr[i] - arr[i-1];
        }
    }
    return profit;
}

int main(){
    int arr[] {10,5, 2,6 ,3 ,21};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << stockbuyandsell(arr,size) << std::endl;
}