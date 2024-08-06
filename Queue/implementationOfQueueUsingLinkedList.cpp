//
// Created by Pranay Kamble on 03/08/24.
//

#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

struct Queue {
    Node *front = nullptr, *rear = nullptr;
    int currSize = 0;

    void enqueue(int data) {
        Node* newNode = new Node(data);
        ++currSize;
        if (currSize == 0) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (currSize == 0) return INT_MIN;
        int store = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        --currSize;
        return store;
    }

    int size() {
        return currSize;
    }

    int getFront() {
        if (currSize == 0) return INT_MIN;
        return front->data;
    }

    int getRear() {
        if (currSize == 0) return INT_MIN;
        return rear->data;
    }

    int isEmpty() {
        return currSize == 0;
    }

    ~Queue() {
        while (front!=nullptr) {
            Node* temp =
        }
    }
};

int main() {

}