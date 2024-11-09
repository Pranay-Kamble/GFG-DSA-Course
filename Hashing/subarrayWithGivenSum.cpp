//
// Created by Pranay Kamble on 07/11/24.
//
#include <iostream>
#include <unordered_set>

/*
//--------------Naive Solution---------------
bool subarrayWithGivenSum(int arr[], int size, int sum) { //Time Complexity: O(n), Auxiliary Space: O(1)
    for (int i = 0; i<size; ++i) {
        int currSum = 0;
        for (int j = i; j<size; ++j) {
            currSum += arr[j];
            if (currSum == sum)
                return true;
        }
    }
    return false;
}
*/

//-------------Efficient Solution-------------
bool subarrayWithGivenSum(int arr[], int size, int sum) { //Time Complexity: O(n), Auxiliary Space: O(n)
    std::unordered_set<int> set;
    int prefixSum = 0;

    for (int i = 0; i<size; ++i) {
        prefixSum += arr[i];
        if (prefixSum == sum || set.find(prefixSum-sum) != set.end())
            return true;
        set.insert(prefixSum);
    }

    return false;
}


int main() {
    int arr[] {5,8,6,13,3,-1};
    const int size = std::size(arr), sum = 22;
    std::cout << std::boolalpha << subarrayWithGivenSum(arr, size, sum) << std::endl;

    return 0;
}