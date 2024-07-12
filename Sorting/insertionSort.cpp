//
// Created by Pranay Kamble on 26/06/24.
//
#include <iostream>

/*-----------------My Approach-------------------  //Very Complex and Long
void rightShifter(int arr[],const int start,const int end) {//Shifts the elements by 1 index right (b/w start and end)
    for (int i {end}; i>start; --i) {  //Time Complexity -> Ɵ(end-start)
        arr[i] = arr[i-1];
    }
}

void insertionSort(int arr[], const int size) {
    for (int i {1}; i<size; ++i) {
        for (int j = 0; j<i; ++j) {
            if (arr[j] > arr[i]) {
                const int temp = arr[i];
                rightShifter(arr,j,i); //This and below statement mimicks the insertion process
                arr[j] = temp;
            }
        }
    }
}

-----------------------------------------------*/

void insertionSort(int arr[], const int size) {
    for (int i = 1; i < size; ++i) {
        const int temp {arr[i]};
        int j = i-1;

        while (j >= 0 && arr[j] > temp) { //Shifting gets handled in this single loop
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = temp;
    }
}


int main() {
    int arr[] {20,3,40,60,10,30};
    insertionSort(arr,sizeof(arr)/sizeof(arr[0]));

    for (int i : arr) {
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    return 0;
}