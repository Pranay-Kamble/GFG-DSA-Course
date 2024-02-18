#include <iostream>

void movezeroes(int arr[], int size){  //Time Complexity = O(n)
    int check {};                      //Auxiliary Space = O(1)
    for(int i{1}; i<size; ++i){
        if(arr[i] == 0 && arr[check] != 0){
            check = i;
            continue;
        }
        if(arr[i] != 0 && arr[check] == 0){
            int copy = arr[i];
            arr[i] = arr[check];
            arr[check] = copy;
            ++check; 
        }
    }
}

int main(){
    int arr[] {10,0,0,0,30,40,0,50,0,0,0,60};
    movezeroes(arr,sizeof(arr)/sizeof(arr[0]));
    for(int i{}; i<sizeof(arr)/sizeof(arr[0]); ++i){
        std::cout << arr[i];
        if(i != sizeof(arr)/sizeof(arr[0]) - 1){
            std::cout << ',';
        }
    }
    std::cout << std::endl;
    return 0;
}