//
// Created by Pranay Kamble on 06/07/24.
//
#include <iostream>

void cycleSort(int arr[], const int size) {
    for (int start {}; start < size-1; ++start) {
        int correctPosition {start};
        int itemToBeFixed{arr[start]};

        for (int i {start+1}; i<size; ++i) {  //Finds the minimum elements before itemToBeFixed
            if (arr[i] < itemToBeFixed)
                ++correctPosition;
        }

        if (correctPosition == start) //Do not swap if it is already at correct position
            continue;

        while (itemToBeFixed == arr[correctPosition]) //Ignore duplicate elements
            ++correctPosition;

        if (correctPosition != start)
            std::swap(arr[correctPosition],itemToBeFixed);  //Sends the item to its correct Index
                                                                //and stores the item at that index in itemToBeFixed
        while(start != correctPosition) { //Repeats the process till an item is not fixed at the start index
            correctPosition = start;

            for (int i {start+1}; i<size; ++i) {
                if (arr[i] < itemToBeFixed)
                    ++correctPosition;
            }

            while (itemToBeFixed == arr[correctPosition])
                ++correctPosition;

            if (itemToBeFixed != arr[correctPosition])
                std::swap(arr[correctPosition], itemToBeFixed);
        }
    }
}

int main() {
    int arr[] {20,40,10,50,30};
    const int size{std::size(arr)};
    cycleSort(arr,size);

    for (const int i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}