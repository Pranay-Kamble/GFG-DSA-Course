//
// Created by Pranay Kamble on 28/07/24.
//
#include <iostream>
#include <stack>

void previousGreater(int arr[], int size) {
    std::stack<int> stack;
    stack.push(arr[0]);
    std::cout << arr[0] << " ";
    for (int i {1}; i<size; ++i) {
        while (!stack.empty() && stack.top() <= arr[i])
            stack.pop();
        std::cout << (stack.empty()?-1:stack.top()) << " ";
        stack.push(arr[i]);
    }
}

int main() {
    int arr[] {20,30,10,5,15};
    const int size {std::size(arr)};
    previousGreater(arr,size);
    return 0;
}