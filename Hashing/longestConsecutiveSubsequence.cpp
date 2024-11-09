//
// Created by Pranay Kamble on 08/11/24.
//
#include <iostream>
#include <vector>
#include <unordered_set>

/*
//------------Naive Solution--------------
int longestConsecutiveSubsequence(std::vector<int> &arr) { //Time Complexity: O(n*logn), Auxiliary Space: O(1)

    std::sort(arr.begin(), arr.end());
    int result = 1, curr = 1;

    for (int i = 1; i<arr.size(); ++i) {
        if (arr[i-1]+1 == arr[i])
            ++curr;
        else
            curr = 1;
        result = std::max(curr, result);
    }
    return result;
}
*/

//--------------Efficient Approach--------------
int longestConsecutiveSubsequence(const std::vector<int> &arr) { //Time Complexity: Theta(n), Auxiliary Space: O(n)
    std::unordered_set<int> set;

    for (int i: arr)
        set.insert(i);

    int result = 1;

    for (int i: set) {
        if (set.find(i-1) != set.end())
            continue;

        int j = 1;
        while (set.find(i+j) != set.end())
            ++j;

        result = std::max(result, j);
    }

    return result;
}



int main() {
    std::vector<int> arr {2,9,4,3,10,7,5,8,6};
    std::cout << "Longest Consecutive Subsequence: " << longestConsecutiveSubsequence(arr) << std::endl;

    return 0;
}