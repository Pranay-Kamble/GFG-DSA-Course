//
// Created by Pranay Kamble on 31/07/24.
//
#include <iostream>
#include <stack>
int const rows {4},columns {4};

int largestRectangularSize(int histogram[],const int size) {
    std::stack<int> stack;
    int maxSize{};
    for (int i{}; i<size; ++i) {
        int currSize {};
        while (!stack.empty() && histogram[stack.top()] >= histogram[i]){
            int top = stack.top();
            stack.pop();
            currSize = histogram[top] * (stack.empty() ? i : stack.top()-i-1);
            maxSize = std::max(currSize,maxSize);
        }
        stack.push(i);
    }
    while (!stack.empty()) {
        int top = stack.top();
        stack.pop();
        int currSize = histogram[top] * (stack.empty() ? size : size-stack.top()-1);
        maxSize = std::max(maxSize,currSize);
    }
    return maxSize;
}

int largestRectangleWithOnes(int arr[rows][columns]) { //Time Complexity = O(rows * columns), Space Complexity = O(2n) = O(n), for stack(in largestarea funct)  and temp array
    int maxSize {};
    int temp[columns];
    for (int i{}; i<columns; ++i) { //Set the temp array equal to first array
        temp[i] = arr[0][i];
    }
    for (int i{1}; i<rows;++i) {
        int currSize {};
        for (int j{0}; j<columns; ++j) {
            temp[j] = (temp[j] * arr[i][j]) + arr[i][j]; //will carry previous value if arr[i][j] != 0 is not encountered
        }
        currSize = largestRectangularSize(temp,columns);
        maxSize = std::max(currSize,maxSize);
    }
    return maxSize;
}

int main() {

    int arr[rows][columns] {{0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0}};
    std::cout << "The largest possible submatrix is " << largestRectangleWithOnes(arr) << std::endl;
    return 0;
}