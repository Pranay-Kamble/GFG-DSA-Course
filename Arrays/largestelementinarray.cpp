#include <iostream>

unsigned int largestelementof(int arr[], int size){ //Returns the index of the largest element in the array
    unsigned int index {};
    for (int i{1}; i<size; ++i){
        if (arr[index] < arr[i]){
            index = i;
        }
    }
    return index;
}

int main(){
    int arr[5] {910,50,20,30};
    std::cout << largestelementof(arr,5);
    return 0;
}