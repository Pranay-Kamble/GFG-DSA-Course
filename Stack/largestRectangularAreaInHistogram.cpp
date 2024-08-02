//
// Created by Pranay Kamble on 30/07/24.
//
#include <iostream>
#include <stack>

/*
//------------Naive Solution----------
int largestRectangularArea(int arr[], const int size) {// Time Complexity = O(n), Space Complexity = O(n)
    int maxArea = INT_MIN;
    for (int i {}; i<size; ++i) {
        int currArea = arr[i];
        for (int j{i-1}; j>=0 ; --j) {  //Need to traverse to the left side
            if (arr[i] <= arr[j])
                currArea += arr[i];
            else
                break;
        }

        for (int j {i+1}; j<size; ++j) { //need to traverse to the right side
            if (arr[i] <= arr[j])
                currArea += arr[i];
            else
                break;
        }

        maxArea = std::max(maxArea, currArea);
    }
    return maxArea;
}*/

/*
//----------------Efficient Solution-----------------
//Use stack to find the previous smaller and next smaller in linear time and preprocessing
int largestRectangularArea(int arr[], const int size) {
    std::stack<int> stack;
    int left[size], right[size];

    stack.push(0);
    left[0] = -1;
    for (int i {1}; i<size; ++i) {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
            stack.pop();
        left[i] = stack.empty() ? -1 : stack.top();
        stack.push(i);
    }

    while (!stack.empty())
        stack.pop();

    stack.push(size);
    for (int i {size-1}; i>=0; --i) {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
            stack.pop();
        right[i] = stack.empty() ? size : stack.top();
        stack.push(i);
    }
    int maxArea = INT_MIN;
    for (int i {0}; i<size; ++i) {
        int currArea = INT_MIN;
        currArea = (right[i] - left[i] - 1) * arr[i];
        maxArea = std::max(currArea, maxArea);
    }
    return maxArea;
}
*/

//------------Best Solution----------
//Process when popping not before pushing

int largestRectangularArea(int arr[], const int size) { // Time Complexity: O(n), Auxiliary Space: O(n), one stack
    std::stack<int> stack;
    int maxArea {0};
    for (int i {}; i<size; ++i) {
        int currArea {0};
        while (!stack.empty() && arr[stack.top()] >= arr[i]) {  //finds the area possible on the left side
            int top = stack.top(); //stores the previous minimum element
            stack.pop(); //remove previous min to expose previous min of previous
            currArea = arr[top] * (stack.empty() ? i : (stack.top()-i-1));
            maxArea = std::max(maxArea, currArea);
        }
        stack.push(i);
    }
    while (!stack.empty()) {  //finds the possible area on the right side
        int top = stack.top();
        stack.pop();
        int currArea = arr[top] * (stack.empty() ? size : size-stack.top()-1); //they do not have a minimum element on right side
        maxArea = std::max(maxArea, currArea);
    }
    return maxArea;
}

int main() {
    int arr[] = {6,2,5,4,1,5,6};
    const int size = std::size(arr);
    std::cout << "The largest area of the histogram is " << largestRectangularArea(arr,size) << std::endl;
    return 0;
}