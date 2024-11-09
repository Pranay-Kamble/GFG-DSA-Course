//
// Created by Pranay Kamble on 09/11/24.
//
#include <iostream>

/*
//-----------Naive Solution-----------
void moreThanNbyK(int arr[], int size, int k) { //Time Complexity: O(n*logn), Auxiliary Space: O(1)
    int limit = size/k;

    std::sort(arr, arr+size);
    int i = 1;
    while (i<size) {
        int count = 1;
        while (i<size && arr[i] == arr[i-1]) {
            ++count; ++i;
        }
        if (count > limit)
            std::cout << arr[i-1] << " ";
        ++i;
    }
}
*/

//-------------Efficient Solution-------------
void moreThanNbyK(int arr[], int size, int k) { //Time Complexity: O(n), Auxiliary Space: O(n)
    std::unordered_map<int,int> map;
    for (int i = 0; i<size; ++i)
        map[arr[i]]++;

    int limit = size/k;

    for (std::pair<int,int> pair: map)
        if (pair.second > limit)
            std::cout << pair.first << " ";
}

int main() {
    int arr[] {10,10,20,30,20,10,10}, size = std::size(arr), k = 2;
    moreThanNbyK(arr, size, k);

    return 0;
}