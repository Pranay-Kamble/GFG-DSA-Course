//
// Created by Pranay Kamble on 05/08/24.
//
#include <iostream>
#include <stack>
#include <queue>


/*
//------------Naive Approach----------------
void reverseQueue(std::queue<int> &queue) {  //Time Complexity: O(n), Space Complexity: O(n)
    std::stack<int> stack;

    while (!queue.empty()) {
        stack.push(queue.front());
        queue.pop();
    }

    while (!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }
}
*/

//-----------Recursive Naive Approach----------
void reverseQueue(std::queue<int> &queue) { //Time Complexity: O(n), Space Complexity: O(n), for recursive stack;
    if (queue.empty())
        return;
    int a = queue.front();
    queue.pop();
    reverseQueue(queue);
    queue.push(a);
}

void printQueue(std::queue<int> queue) {
    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<int> queue;
    for (int i {}; i<5; ++i) {
        queue.push(i);
    }
    printQueue(queue);
    reverseQueue(queue);
    printQueue(queue);

    return 0;
}