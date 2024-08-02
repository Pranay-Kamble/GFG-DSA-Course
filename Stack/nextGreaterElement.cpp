//
// Created by Pranay Kamble on 29/07/24.
//
#include <iostream>
#include <stack>

/*
//-----------Naive Approach-----------------
void nextGreaterElement(int arr[], int size) { //Time Complexity = O(n^2), Auxiliary Space = O(1)
    for (int i {}; i<size ; ++i) {
        bool flag = false;
        for (int j {i+1}; j<size; ++j) {
            if (arr[i] < arr[j]) {
                std::cout << arr[i] << "->" << arr[j] << "\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            std::cout << arr[i] << "-> -1\n";
    }
}*/

//------------Efficient Approach--------
void nextGreaterElement(int arr[], int size) {
    std::stack<int> stack;
    stack.push(arr[size-1]);
    std::cout << arr[size-1] << "-> -1\n";
    for (int i{size-2}; i>=0; --i) {
        while (!stack.empty() && stack.top()<=arr[i])
            stack.pop();
        std::cout << arr[i] << "->" << (stack.empty() ? -1 : stack.top()) << "\n";
        stack.push(arr[i]);
    }
}

int main() {
    int arr[] {5,15,10,8,6,12,9,18};
    const int size {std::size(arr)};
    nextGreaterElement(arr,size);
    return 0;
}