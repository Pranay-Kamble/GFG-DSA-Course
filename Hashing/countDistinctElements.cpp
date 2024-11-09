//
// Created by Pranay Kamble on 24/10/24.
//
#include <iostream>
#include <unordered_set>

/*
//-------------Naive Approach------------
int countDistinct(int arr[], int size) { //Time Complexity: O(n*n), Auxiliary Space: O(1)
    int distinct = 0;
    for (int i = 0; i<size; ++i) {
        bool flag = true;
        for (int j = 0; j<i; ++j) {
            if (arr[i] == arr[j])
                flag = false;
        }

        if (flag)
            ++distinct;
    }

    return distinct;
}

*/
//--------------Efficient Approach-----------

int countDistinct(int arr[], int size) { //Time Complexity: O(n), Auxiliary Space: O(n)
    std::unordered_set<int> set;
    for (int i = 0; i<size; ++i)
        set.insert(arr[i]);

    return set.size();
}

int main() {
    int arr[] {10,20,10,20,30};
    int size {std::size(arr)};

    std::cout << "Distinct Count: " << countDistinct(arr, size) << std::endl;
    return 0;
}