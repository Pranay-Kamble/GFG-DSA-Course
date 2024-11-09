//
// Created by Pranay Kamble on 06/11/24.
//
#include <iostream>
#include <unordered_set>
#include <vector>


/*
//-----------Naive Solution--------------------

std::vector<int> intersection(const std::vector<int> &arr1, const std::vector<int> &arr2) { //Time: O(m * n), Space: O(1)
    std::vector<int> result;

    for (int i: arr1) {
        for (int j: arr2)
            if (i == j){
                result.push_back(i);
                break;
            }
    }

    return result;
}
*/

//-----------Efficient Approach---------------
std::vector<int> intersection(const std::vector<int> &arr1, const std::vector<int> &arr2) { //Time: Theta(m+n), Space: O(n)
    std::vector<int> result;
    std::unordered_set<int> set;

    for (int i: arr2)
        set.insert(i);

    for (int i: arr1)
        if (set.find(i) != set.end())
            result.push_back(i);

    return result;
}

int main() {
    std::vector<int> arr1 = {10, 20, 30}, arr2 = {30, 20, 10}, result = intersection(arr1, arr2);

    for (int i: result)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
