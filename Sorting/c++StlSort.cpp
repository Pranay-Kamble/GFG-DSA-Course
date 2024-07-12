//
// Created by Pranay Kamble on 25/06/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int arr[5] {4,2,5,31,2};

    std::sort(arr,arr+5);

    for (const int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector <int> vector {10,203,0403,40};
    std::sort(vector.begin(), vector.end());

    for (int i = 0; i<vector.size(); ++i) {
        std::cout << vector[i] << ' ';
    }
    std::cout << std::endl;

}