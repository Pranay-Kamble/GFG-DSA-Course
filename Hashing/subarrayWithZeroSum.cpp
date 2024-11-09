//
// Created by Pranay Kamble on 06/11/24.
//
#include <iostream>
#include <unordered_set>

/*
//-------------Naive Approach-------------
bool subarrayWithZeroSum(int arr[], int size) { //Time Complexity: O(n*n), Auxiliary Space: O(1)
    for (int i = 0; i<size; ++i) {
        int sum = 0;
        for (int j = i; j<size; ++j) {
            sum += arr[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
}

*/
//-------------Efficient Approach-----------
void prefixSum(int arr[], int size) {
    for (int i = 1; i<size; ++i) {
        arr[i] += arr[i-1];
    }
}

bool subarrayWithZeroSum(int arr[], int size) { //Time Complexity: O(n), Auxiliary Space: O(n)
    prefixSum(arr, size);

    std::unordered_set<int> set;
    for (int i {}; i<size; ++i) {
        if (set.find(arr[i]) != set.end() || arr[i] == 0) //if the prefix sum is already present or the prefix sum is zero at some subarray
            return true;

        set.insert(arr[i]);
    }
    return false;
}

int main() {
    int arr[] {-3,4,-3,-1,1};
    int size {std::size(arr)};

    std::cout << std::boolalpha << subarrayWithZeroSum(arr, size) << std::endl;

    return 0;
}