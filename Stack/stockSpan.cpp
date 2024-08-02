//
// Created by Pranay Kamble on 28/07/24.
//
#include <iostream>
#include <stack>

/*
//------------Naive Solution---------------
void stockSpan(int arr[], int size) { //Time Complexity = O(n^2), Space Complexity = Theta(1)
    int span {1};
    for (int i {}; i<size; ++i) {
        for (int j {i-1}; j>=0; --j) {
            if (arr[j] <= arr[i])
                span++;
            else
                break;
        }
        std::cout << arr[i] << "->" << span << std::endl;
        span = 1;
    }
}*/

void stockSpan(int arr[], int size) { //Time Complexity = Theta(n) and not quadratic. Because
    std::stack<int> stack;
    int span {1};
    stack.push(0);
    std::cout << arr[0] << "-> 1\n";
    for (int i {1}; i<size; ++i) {
        while (!stack.empty() && arr[stack.top()] <= arr[i])
            stack.pop();
        span = stack.empty() ? i+1 : i-(stack.top());
        std::cout << arr[i] << "->" << span << "\n";
        stack.push(i); //new previous greater
    }
}

int main() {
    int arr[] {60,10,20,40,35,30,50,70,65};
    const int size {std::size(arr)};
    stockSpan(arr,size);
    return 0;
}