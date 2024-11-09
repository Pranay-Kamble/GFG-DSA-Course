//
// Created by Pranay Kamble on 06/11/24.
//

#include <iostream>
#include <unordered_set>
#include <vector>

/*
//--------------Naive Approach--------------

int unionCount(const std::vector<int> &arr1, const std::vector<int> &arr2) { //Time Complexity: O((m+n)*(m+n)) = O(k * k), Auxiliary Space: O(m+n) = O(k)
    std::vector<int> larger;
    int count = 0;
    for (int i: arr1)
        larger.push_back(i);

    for (int j: arr2)
        larger.push_back(j);

    for (int i = 0; i<larger.size(); ++i) {
        bool flag = true;
        for (int j = i+1; j<larger.size(); ++j)
            if (larger[i] == larger[j]) {
                flag = false;
                break;
            }
        if (flag)
            ++count;
    }

    return count;
}

int unionCount(const std::vector<int> &arr1, const std::vector<int> &arr2) { //Time Complexity: O(n * (m+n)), Auxiliary Space: O(m+n)
    std::vector<int> temp;
    int count = 0;

    for (int i: arr1) {
        bool flag = true;
        for (int j: temp) {
            if (i == j) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++count;
            temp.push_back(i);
        }
    }

    for (int i: arr2) {
        bool flag = true;
        for (int j: temp) {
            if (i == j) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++count;
            temp.push_back(i);
        }
    }

    return count;
}*/

//-----------Efficient Approach-------------
int unionCount(const std::vector<int> &arr1, const std::vector<int> &arr2) { //Time Complexity: O(max(m,n)), Auxiliary Space: O(m+n)
    std::unordered_set<int> set;

    for (int i: arr1)
        set.insert(i);

    for (int j: arr2)
        set.insert(j);

    return set.size();
}


int main() {
    std::vector<int> arr1 = {3,3,3}, arr2 = {3,3};
    std::cout << "Union Count: " << unionCount(arr1, arr2) << std::endl;

    return 0;
}