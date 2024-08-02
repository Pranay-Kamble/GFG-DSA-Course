//
// Created by Pranay Kamble on 27/07/24.
//
#include <iostream>

class TwoStacks {
private:
    int *arr = nullptr;
    int capacity {};

    int top1 = -1;
    int top2;

public:
    TwoStacks(int capacity) { //Constructor
        this->capacity = capacity;
        top2 = capacity;
        arr = new int[capacity];
    }

    ~TwoStacks() { //Destructor
        delete [] arr;  //Deallocating memory allocated to arr
    }

    bool push1(int data) {
        if (top1 + 1 >= top2) //Overflow of stack 1
            return false;
        arr[++top1] = data;
        return true;
    }

    bool push2(int data) {
        if (top2-1 <= top1) //overflow of stack 2
            return false;
        arr[--top2] = data;
        return true;
    }

    int pop1() {
        if (top1 == -1) //Underflow in stack1
            return -1;
        top1--;
        return arr[top1+1];
    }

    int pop2() {
        if (top2 == capacity) //Underflow in stack2
            return -1;
        top2++;
        return arr[top2-1];
    }

    int peek1() {
        if (top1 == -1) //Underflow in stack1
            return -1;
        return arr[top1];
    }

    int peek2() {
        if (top2 == capacity) //Underflow in stack2
            return -1;
        return arr[top2];
    }

    bool empty1() {
        return top1 == -1;
    }
    bool empty2() {
        return top2 == capacity;
    }

    int size1() {
        return top1+1;
    }
    int size2() {
        return capacity - top2;
    }
};

int main() {
    TwoStacks stack(10);
    stack.push1(10);
    stack.push1(20);
    stack.push1(30);
    stack.push1(30);
    stack.push1(30);
    stack.push1(30);
    stack.push1(40);
    stack.push2(1);
    stack.push2(2);
    stack.push2(3);
    stack.push2(4);
    stack.push2(5);
    stack.push2(5);
    stack.push2(5);
    stack.push2(5);
    stack.push2(5);
    stack.push2(5);

    while (!stack.empty1())
        std::cout << stack.pop1() << std::endl;

    while(!stack.empty2())
        std::cout << stack.pop2() << std::endl;

    return 0;
}