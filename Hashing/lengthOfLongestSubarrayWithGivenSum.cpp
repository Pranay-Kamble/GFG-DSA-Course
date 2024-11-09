//
// Created by Pranay Kamble on 07/11/24.
//
#include <iostream>
#include <unordered_map>

/*
//---------------Naive Approach------------------
int longestSubarray(int arr[], int size, int sum) { //Time Complexity: Theta(n*n), Auxiliary Space: Theta(1)
    int result = 0;

    for (int i = 0; i<size; ++i) {
        int curr = 0;
        for (int j = i; j<size; ++j) {
            curr += arr[j];
            if (curr == sum) {
                result = std::max(result, j-i+1);
            }
        }
    }

    return result;
}
*/

//---------------Efficient Approach--------------
int longestSubarray(int arr[], int size, int sum) { //Time C
    std::unordered_map<int,int> map;
    int prefixSum = 0, result = 0;
    for (int i = 0; i<size; ++i) {
        prefixSum += arr[i];
        if (prefixSum == sum)
            result = i+1;
        if (map.find(prefixSum - sum) != map.end())
            result = std::max(result, i - map[prefixSum - sum]);

        if (map.find(prefixSum) == map.end()) //If there are two subarrays with same sum then take the first subarray
            map[prefixSum] = i;
    }

    return result;
}

int main() {
    int arr[] {8,3,1,5,6,2}, size = std::size(arr), sum = 2;
    std::cout << "Max Length: " << longestSubarray(arr, size, sum) << std::endl;

    return 0;
}