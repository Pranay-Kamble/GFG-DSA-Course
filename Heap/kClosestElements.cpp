//
// Created by Pranay Kamble on 01/10/24.
//
#include <iostream>
#include <queue>

/*
//-------------Naive Approach------------
void kClosestElements(int arr[], int size, int num , int k) { //Time Complexity: O(N + K*logN), Auxiliary Space: O(N)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int,int>>> pQueue;

    for (int i{}; i<size; ++i)
        pQueue.push({abs(arr[i]-num), arr[i]});

    for (int i{}; i<k; ++i) {
        std::cout << pQueue.top().second << " ";
        pQueue.pop();
    }
    std::cout << std::endl;
}

*/
//--------------Efficient Approach------------
void kClosestElements(int arr[], int size, int num, int k) { //Time Complexity: O(K + K*logN), Auxiliary Space: O(N)
    std::priority_queue<std::pair<int, int>> pQueue;

    for (int i{}; i<k; ++i)
        pQueue.push({abs(arr[i]-num), arr[i]});

    for (int i {k}; i<size; ++i) {
        if (abs(arr[i]-num) < abs(pQueue.top().first)) {
            pQueue.pop();
            pQueue.push({abs(arr[i] - num), arr[i]});
        }
    }

    for (int i{}; i<k; ++i) {
        std::cout << pQueue.top().second << " ";
        pQueue.pop();
    }
    std::cout << std::endl;
}

int main() {
    int arr[] {30,40,32,33,36,37};
    int size {std::size(arr)};
    int k = 3;
    int num = 38;

    printf("The %d closest elements to %d :", k, num);
    kClosestElements(arr, size, num, k);
    std::cout << std::endl;

    return 0;
}