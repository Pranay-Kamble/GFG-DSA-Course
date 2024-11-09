//
// Created by Pranay Kamble on 24/10/24.
//
#include <iostream>
#include <unordered_map>


/*
//---------------Naive Approach--------------------
void frequencyOfElements(int arr[], int size) { //Time Complexity: O(n), Auxiliary Space: O(1)
    for (int i = 0; i<size; ++i) {
        int count = 1;
        bool flag = true;
        for (int j = 0; j<size; ++j) {
            if (i == j) continue;
            if (arr[i] == arr[j]) {
                ++count;
                if (j>i)
                    flag = false;
            }
        }
        if (flag)
            printf("{%d : %d} ", arr[i], count);
    }
}*/

//------------Efficient Approach-----------------
void frequencyOfElements(int arr[], int size) {
    std::unordered_map<int , int> map;

    for (int i = 0; i<size; ++i)
        map[arr[i]]++;

    for (std::pair<int, int> pair: map) {
        printf("{%d:%d} ", pair.first, pair.second);
    }
}


int main() {
    int arr[] = {10,12,10,15,10,20,12,12};
    int size = std::size(arr);
    frequencyOfElements(arr, size);

    return 0;
}