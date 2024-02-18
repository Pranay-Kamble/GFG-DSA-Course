#include <iostream>

void reverse(int arr[], int size){
    int index {size-1};
    for(int i{}; i<size/2 ; ++i){
        int copy {arr[i]};
        arr[i] =  arr[index-i];
        arr[index-i] = copy;
    }
}

int main(){
    int arr[] {9,8,0,7,6,5,4,3,2,1};
    reverse(arr,sizeof(arr)/sizeof(arr[0]));
    
    for(int i{}; i<sizeof(arr)/sizeof(arr[0]); ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}