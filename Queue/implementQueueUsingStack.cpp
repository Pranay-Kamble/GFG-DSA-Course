//
// Created by Pranay Kamble on 04/08/24.
//
#include <iostream>
#include <stack>


struct Queue {
    std::stack<int> stack, temp;

    void enqueue(int data) {
        if (stack.empty()) {
            stack.push(data);
            return;
        }

        while (!stack.empty()) {
            temp.push(stack.top());
            stack.pop();
        }
        stack.push(data);
        while (!temp.empty()) {
            stack.push(temp.top());
            temp.pop();
        }
    }

    int dequeue() {
        if (stack.empty()) return INT_MIN;
        int res = stack.top();
        stack.pop();
        return res;
    }

    int size() {
        return stack.size();
    }

    int empty() {
        return stack.empty();
    }
};


int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    while (!queue.empty()) {
        std::cout << queue.dequeue() << ' ' ;
    }
    std::cout << std::endl;
    return 0;
}