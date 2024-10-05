//
// Created by Pranay Kamble on 02/10/24.
//
#include <iostream>
#include <queue>
#include <vector>

/*
//-----------------Naive Approach----------------
std::vector<float> medianOfStream(const std::vector<int> &vector) { //Time Complexity: O(N*N), Auxiliary Space: O(N*N)
    std::priority_queue<int, std::vector<int>, std::greater<int>> pQueue;
    std::vector<float> result;

    for (int i{}; i<vector.size(); ++i) {
        std::vector<int> temp;
        for (int j {}; j<=i; ++j) {
            pQueue.push(vector[j]);
        }

        while (!pQueue.empty()) {
            temp.push_back(pQueue.top());
            pQueue.pop();
        }

        if (temp.size()%2) {
            result.push_back(temp[temp.size()/2]);
        }else {
            result.push_back((temp[temp.size()/2]+temp[(temp.size()/2) - 1])/2.0);
        }
    }

    return result;
}*/

//------------------Efficient Approach-------------------

std::vector<float> medianOfStream(const std::vector<int> &arr) { //Time Complexity: O(N * logN), Auxiliary Space: O(N)
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::vector<float> result;

    maxHeap.push(arr[0]);
    result.push_back(arr[0]);
    for (int i {1}; i<arr.size(); ++i) {
        if (maxHeap.size() == minHeap.size()) { //Element should be inserted in the max heap
            if (maxHeap.top() >= arr[i])
                maxHeap.push(arr[i]);
            else {
                minHeap.push(arr[i]);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            result.push_back(maxHeap.top());
        }else { //Element should be inserted in the min heap
            if (maxHeap.top() <= arr[i])
                minHeap.push(arr[i]);
            else {
                maxHeap.push(arr[i]);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            result.push_back((maxHeap.top() + minHeap.top())/2.0);
        }
    }

    return result;
}



int main() {
    std::vector<int> input {12,15,10,5,8,7,16};
    std::vector<float> median {medianOfStream(input)};

    for (float i: median) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}