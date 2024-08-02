//
// Created by Pranay Kamble on 25/07/24.
//
#include <iostream>
#include <vector>

struct FixedStack { //Fixed Size Array Implementation
    int capacity = 0; //size of the stack
    int top = -1; //index of last filled item
    int *arr;

    FixedStack(int size) {
        this->capacity = size;
        arr = new int[size];
        for (int i {}; i<size; ++i)
            arr[i] = 0;
    }

    ~FixedStack() {
        delete [] arr;
    }

    void push(int data) {
        if (top == capacity-1) { //Overflow
            std::cout << "Overflow" << std::endl;
            return;
        }
        ++top;
        arr[top] = data;
    }

    int size() {
        return top+1;
    }

    int pop() {
        if (top == -1) { //Underflow
            std::cout << "Underflow" << std::endl;
            return -1;
        }
        int copy {arr[top]};
        --top;
        return copy;
    }

    int peek() {
        if (top == -1) {
            return -1;
        }
        return (arr[top]);
    }

    bool isEmpty() {
        return top == -1;
    }
};


struct DynamicStack {
    std::vector<int> arr;

    void push(int data) {
        arr.push_back(data);
    }

    int pop() {
        if (arr.size() == 0) return -1; //Underflow check
        int res = arr.back();
        arr.pop_back();
        return res;
    }

    int peek() {
        if (arr.size() == 0) return -1; //Underflow check
        return arr.back();
    }

    bool isEmpty() {
        return arr.size() == 0;
    }

    int size() {
        return arr.size();
    }

};

int main() {
    DynamicStack stack;

    stack.push(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.size() << std::endl;
    std::cout << stack.peek() << std::endl;
    std::cout << std::boolalpha << stack.isEmpty() << std::endl;
    return 0;
}