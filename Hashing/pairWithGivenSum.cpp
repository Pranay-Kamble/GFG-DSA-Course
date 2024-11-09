//
// Created by Pranay Kamble on 06/11/24.
//
#include <iostream>
#include <unordered_set>

/*
//-------------Naive Approach------------------
bool isPairPresent(int arr[], int size, int sum) { //Time Complexity: O(n*n), Auxiliary Space: O(1)
    for (int i = 0; i<size-1; ++i) {
        for (int j = i+1; j<size; ++j) {
            if (arr[i] + arr[j] == sum)
                return true;
        }
    }

    return false;
}
*/


//--------------Efficient Approach-----------------
bool isPairPresent(int arr[], int size, int sum) { //Time Complexity: O(n), Auxiliary Space: O(n)
    std::unordered_set<int> set;

    for (int i {}; i<size; ++i) {
        if (set.find(sum-arr[i]) != set.end())
            return true;
        set.insert(arr[i]);
    }

    return false;
}


int main() {
    int arr[] {5,8,-3,6};
    int size = std::size(arr);
    int sum = 3;
    std::cout << std::boolalpha << isPairPresent(arr, size, sum) << std::endl;

    return 0;
}