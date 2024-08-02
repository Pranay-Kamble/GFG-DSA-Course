//
// Created by Pranay Kamble on 31/07/24.
//
#include <iostream>
#include <stack>
struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

/*
//Approach-1------Using linked list for stack and extra linked list to store a minLinkedList
struct MinStack {
    Node* stack = nullptr;
    Node* minStack = nullptr;

    void push(int data) {
        Node* node1 = new Node(data);
        Node* node2;
        if (stack == nullptr || minStack->data > data) {
            node2 = new Node(data);
            node1->next = stack;
            node2->next = minStack;
            stack = node1;
            minStack = node2;
            return;
        }
        node1->next = stack;
        node2 = new Node(minStack->data);
        node2->next = minStack;
        minStack = node2;
        stack = node1;
    }

    int pop() {
        if (stack == nullptr) return -1;
        Node* temp = stack->next; //deleting the top node
        int res = stack->data;
        delete stack;
        stack = temp;

        temp = minStack->next; //deleting the corresponding min node
        delete minStack;
        minStack = temp;
        return res;
    }

    int getMin() {
        if (minStack == nullptr) return INT_MAX;
        return minStack->data;
    }

    ~MinStack() {
        while (stack != nullptr) {
            Node* next= stack->next;
            delete stack;
            stack = next;
        }
        while (minStack != nullptr) {
            Node* next = minStack->next;
            delete minStack;
            minStack = next;
        }
    }
};
*/

//Approach-2  Using stack class to maintain stack and minStack, assume all elements are unique
/*
struct MinStack {
    std::stack<int> stack;
    std::stack<int> minStack;

    void push(int data) {
        stack.push(data);
        if (minStack.empty() || minStack.top() >= data)
            minStack.push(data);
    }

    int pop() {
        if (stack.empty())
            return -1;
        int top = stack.top();
        if (minStack.top() == stack.top())
            minStack.pop();
        stack.pop();
        return top;
    }

    int getMin() {
        if (minStack.empty())
            return INT_MAX;
        return minStack.top();
    }
};
*/

//Approach-3 (Tricky)- Only for positive elements - Using a min variable which stores the min element
/*struct MinStack {
    std::stack<int> stack;
    int min = INT_MAX;

    void push(int data) {
        if (min > data) {
            stack.push(data-min); //will help in retrieving previous min when this item will be popped
            min = data;
        }else {
            stack.push(data);
        }
    }

    int pop() {
        if (stack.empty())
            return -1;
        int ret = -1;
        if (stack.top() < 0) {
            ret = min;
            min -= stack.top();
        } else {
            ret = stack.top();
        }
        stack.pop();
        return ret;
    }

    int getMin() {
        return min;
    }

    int top() {
        if (stack.top < 0)
            return (min-stack.top());
        return stack.top();
    }
};*/

//Approach-4 - (extension of previous approach, we just change the way to store a special number )- works for all numbers
struct MinStack {
    std::stack<int> stack;
    int min {INT_MAX};

    void push(int data) {
        if (min > data) {
            stack.push((2*data) - min);  //formula:  special = (2* newMin) - prevMin
            min = data;
        } else
            stack.push(data);
    }

    int pop() {
        int res = -1;
        if (stack.empty())
           return res;
        if (stack.top() < min) { //special value found  -> prevMin = (2* newMin) - special
            res = min;
            min = (2*min) - stack.top();
        }else
            res = stack.top();
        stack.pop();
        return res;
    }

    int getMin() {
        return min;
    }

    int top() {
        if (stack.empty())
            return -1;
        if (stack.top() < min)
            return min;
        return stack.top();
    }
};


int main() {
    MinStack stack;
    stack.push(5);
    stack.push(10);
    stack.push(20);
    stack.push(2);
    stack.push(6);
    stack.push(4);
    stack.pop();
    stack.pop();
    stack.push(2);
    stack.pop();
    stack.push(1);
    stack.pop();
    stack.pop();
    stack.push(0);
    stack.pop();
    stack.pop();
    std::cout << stack.getMin() << std::endl;
    return 0;
}