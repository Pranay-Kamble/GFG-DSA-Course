//
// Created by Pranay Kamble on 08/08/24.
//
#include <iostream>
#include <deque>

/*
//-----------Naive Approach--------------
//Using a double for-loop for every sub

void maxOfAllK(int arr[], int size, int k) { //Time Complexity: O(n*k), Auxiliary Space: O(1)
    for (int i{}; i<size-k+1; ++i) {
        int max = arr[i];
        for (int j{i+1}; j<i+k; ++j) {
            max = std::max(max, arr[j]);
        }
        std::cout << max << " ";
    }
    std::cout << std::endl;
}
*/

//-----------Efficient Approach----------
void maxOfAllK(int arr[], int size, int k) {
    if (k<=0 || k>size) {
        std::cout << "Invalid Subarray Size" << std::endl;
        return;
    }
    std::deque<int> deque;
    for (int i{}; i<k; ++i) {
        while (!deque.empty() && arr[deque.back()] <= arr[i]) //remove elements that are smaller than current element
            deque.pop_back();
        deque.push_back(i);
    }

    for (int i{k};i<size; ++i) {
        std::cout << arr[deque.front()] << " ";

        while (!deque.empty() && deque.front() <= i-k) //remove the elements that are out of window size
            deque.pop_front();

        while (!deque.empty() && arr[i] >= arr[deque.back()]) //remove all smaller elements than current inserting element
            deque.pop_back();
        deque.push_back(i);
    }
    std::cout << arr[deque.front()] << std::endl; //print maximum of last subarray
}

int main() {
    int arr[] {12, 1, 78, 90, 57, 89, 56};
    int size {std::size(arr)};
    maxOfAllK(arr,size,2);
    return 0;
}