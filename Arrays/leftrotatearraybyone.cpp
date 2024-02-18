#include <iostream>

void leftrotatearray(int arr[], int size){
    int first = arr[0];
    for(int i{}; i<size-1; ++i){
        arr[i] = arr[i+1];
    }
    arr[size-1] = first;
}

int main(){
    int arr[] {10,20,30,40,50};
    leftrotatearray(arr,sizeof(arr)/sizeof(arr[0]));
    for (int i{}; i<sizeof(arr)/sizeof(arr[0]);++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}