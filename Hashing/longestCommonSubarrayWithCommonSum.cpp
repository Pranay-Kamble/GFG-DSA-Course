//
// Created by Pranay Kamble on 08/11/24.
//
#include <iostream>
#include <unordered_map>

/*
//--------------Naive Solution---------------
int longestWithCommonSubarraySum(const std::vector<int> &arr1, const std::vector<int> &arr2) {
    int result = 0;                                 //Time Complexity: Theta(n*n), Auxiliary Space: O(1)
    for (int i = 0; i<arr1.size(); ++i) {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j<arr1.size(); ++j) {
            sum1 += arr1[j];
            sum2 += arr2[j];

            if (sum1 == sum2) //this subarray has common sum in both arrays
                result = std::max(result, j+1-i);
        }
    }

    return result;
}
*/

//---------------Efficient Solution-----------
int longestWithCommonSubarraySum(const std::vector<int> &arr1, const std::vector<int> &arr2) {
    std::vector<int> temp (arr1.size());

    for (int i = 0; i<arr1.size(); ++i) {
        temp[i] = arr1[i] - arr2[i];
    }

    int result = 0, prefix = 0;
    std::unordered_map<int,int> map;

    for (int i = 0 ; i<temp.size(); ++i) {
        prefix += temp[i];
        if (prefix == 0)
            result = i+1;
        else if (map.find(prefix) != map.end()) {
            result = std::max(result, i - map[prefix]);
        }

        if (map.find(prefix) == map.end())
            map[prefix] = i;
    }

    return result;
}


int main() {
    std::vector<int> arr1 = {0,1,0,0,0,0}, arr2 = {1,0,1,0,0,1};
    std::cout << "Longest Common Sum Length: " << longestWithCommonSubarraySum(arr1, arr2) << std::endl;

    return 0;
}