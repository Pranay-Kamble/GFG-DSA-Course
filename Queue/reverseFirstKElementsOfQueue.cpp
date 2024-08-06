//
// Created by Pranay Kamble on 04/08/24.
//
#include <iostream>
#include <stack>
#include <queue>

void reverseFirstK(std::queue<int> &queue, int k) {  //Time Complexity: O(n), Auxiliary Space: O(k)
    std::stack<int> stack;

    for (int i{}; i<k; ++i) {
        stack.push(queue.front());
        queue.pop();
    }
    while (!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }

    for (int i{}; i<(queue.size()-k); ++i) {
        queue.push(queue.front());
        queue.pop();
    }

}

int main() {
    std::queue<int> queue;
    for (int i {}; i<6; ++i) {
        queue.push(i);
    }
    reverseFirstK(queue,3);

    std::cout << "Displaying the reverse queue:\n";
    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;

    return 0;
}