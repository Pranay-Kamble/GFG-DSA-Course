//
// Created by Pranay Kamble on 26/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

struct LinkedListStack {
    Node* head = nullptr;
    int currentSize = 0;
    void push(int data) {
        Node* node = new Node(data);
        node->next = head;
        head = node;
        ++currentSize;
    }

    int pop() {
        if (head == nullptr) {
            return INT_MIN;
        }
        Node* del = head;
        int data = del->data;
        head = head->next;
        delete del;
        --currentSize;
        return data;
    }

    int peek() {
        if (head == nullptr) {
            return INT_MIN;
        }
        return head->data;
    }

    bool isEmpty() {
        return currentSize==0;
    }

    int size() {
        return this->currentSize;
    }

    ~LinkedListStack() {
        Node* prev = head;
        while (head != nullptr) {
            prev = head;
            head = head->next;
            delete prev;
        }
    }
};


int main() {
    LinkedListStack stack;

    stack.push(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    std::cout << stack.peek() << std::endl;
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