//
// Created by Pranay Kamble on 04/08/24.
//
#include <iostream>
#include <queue>

struct Stack {
    std::queue<int> queue,temp;

    int top() {
        if (!queue.empty())
            return queue.front();
        return INT_MIN;
    }

    void push(int data) {
        if (queue.empty()) {
            queue.push(data);
            return ;
        }
        while (!queue.empty()) {
            temp.push(queue.front());
            queue.pop();
        }

        queue.push(data);
        while (!temp.empty()) {
            queue.push(temp.front());
            temp.pop();
        }
    }

    int pop() {
        if (queue.empty()) return INT_MIN;
        int res = queue.front();
        queue.pop();
        return res;
    }

    int size() {
        return queue.size();
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << stack.pop() << " " << stack.pop() << " " << stack.pop() << std::endl;
    return 0;
}