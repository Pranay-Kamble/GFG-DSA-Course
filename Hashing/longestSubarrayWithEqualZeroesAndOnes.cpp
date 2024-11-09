//
// Created by Pranay Kamble on 07/11/24.
//
#include <iostream>

/*//--------------Naive Approach--------------
int longestWithEqualZeroAndOne(int arr[], int size) { //Time Complexity: Theta(n*n), Auxiliary Space: O(1)
    int result = 0;
    for (int i = 0; i<size; ++i) {
        int toggle = 0;
        for (int j = i; j<size; ++j) {
            toggle += (arr[j] == 0) ? -1 : 1;

            if (toggle == 0)
                result = std::max(result, j-i+1);
        }
    }

    return result;
}*/

//---------------Efficient Solution------------
int longestWithEqualZeroAndOne(int arr[], int size) { //Time Complexity: Theta(n), Auxiliary Space: O(1)
    int prefix = 0, result = 0;
    std::unordered_map<int,int> map;

    for (int i = 0; i<size; ++i) {
        prefix += arr[i]; //keeps count of number of 1's encountered till that point

        if (i+1-prefix == prefix) // i+1-prefix gives the count of number of zeroes, if it is equal to number of ones
            result = i+1;
        if (map.find(i+1 - prefix) != map.end()) {
            result = std::max(result, i-map[i+1-arr[i]]);
        }

        if (map.find(prefix) == map.end())
            map[prefix] = i;
    }

    return result;
}

int main() {
    int arr[] {1,0,0,1,0,1,1}, size = std::size(arr);
    std::cout << "Max Length: " << longestWithEqualZeroAndOne(arr, size) << std::endl;

    return 0;
}