//
// Created by Pranay Kamble on 09/11/24.
//
#include <iostream>
#include <unordered_map>

void countDistinctInWindow(int arr[], int size, int k) { //Time Complexity: O(n), Auxiliary Space: O(k)
    std::unordered_map<int,int> map;

    for (int i = 0; i<k; ++i)
        map[arr[i]]++;
    std::cout << map.size() << " ";

    for (int i = k; i<size; ++i) {
        if (map[arr[i-k]] > 0)
            --map[arr[i-k]];

        if (map[arr[i-k]] == 0)
            map.erase(map.find(arr[i+1-k]));

        map[arr[i]]++;
        std::cout << map.size() << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] {10,20,10,10,30,40}, size = std::size(arr), k = 4;
    std::cout << "The distinct elements in each window are: " ; countDistinctInWindow(arr,size,k);

    return 0;
}