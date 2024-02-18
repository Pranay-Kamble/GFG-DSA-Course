#include <iostream>

int removeduplicates(int arr[] , int size, int result = 1){        //Time Complexity = O(n)
    int check {arr[0]};
    for(int i{1}; i < size; ++i){  //makes all duplicates in array to zero
        if(arr[i] == check){
            arr[i] = 0;
        }
        else{
            check = arr[i];
            ++result;        
        }
    }
    check = 0;
    for(int i{1}; i<size; ++i){         //swaps all non zero values with the first occurring zero in the array
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
    return result;
}
int main(){
    int arr[] {10,10,10,10,10,10}; //{1,2,0,10,0,40,0,0,0,0,50,0}
    std::cout << "New Size is " << removeduplicates(arr,sizeof(arr)/sizeof(arr[0]))<< std::endl;
    for (int i{}; i<sizeof(arr)/sizeof(arr[0]); ++i){
        std::cout << arr[i] ;
        if(i != sizeof(arr)/sizeof(arr[0])-1)
            std::cout << ",";
    }
    std::cout << '\n';
    return 0;
}