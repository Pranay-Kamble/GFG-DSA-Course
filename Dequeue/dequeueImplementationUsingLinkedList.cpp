//
// Created by Pranay Kamble on 06/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node (int data) {
        this->data = data;
    }
};


struct Dequeue {
    Node *front = nullptr, *rear = nullptr;
    int currSize {};

    void insertFront(int data) {
        Node *node = new Node(data);
         ++currSize;
        if (front == nullptr) {
            front = rear = node;
            return;
        }

        node->next = front;
        front->prev = node;
        front = node;
    }

    void insertRear(int data) {
        Node *node = new Node(data);
        ++currSize;
        if (front == nullptr) {
            front = rear = node;
            return;
        }

        rear->next = node;
        node->prev = rear;
        rear = node;
    }

    int deleteFront() {
        if (front == nullptr) return INT_MIN;
        int ret = front->data;
        if (front->next == nullptr) {
            delete front;
            front = rear = nullptr;
        }else {
            front = front->next;
            delete front->prev;
            front->prev = nullptr;
        }
        --currSize;
        return ret;
    }

    int deleteRear() {
        if (rear == nullptr) return INT_MIN;
        int ret = rear->data;
        if (rear->prev == nullptr) {
            delete rear;
            rear = front = nullptr;
        }else {
            rear = rear->prev;
            delete rear->next;
            rear->next = nullptr;
        }
        --currSize;
        return ret;
    }

    int getFront() {
        if (front == nullptr) return INT_MIN;
        return front->data;
    }

    int getRear() {
        if (rear == nullptr) return INT_MIN;
        return rear->data;
    }

    bool empty() {
        return currSize == 0;
    }

    int size() {
        return currSize;
    }
};


int main() {
    Dequeue deq;
    for (int i{}; i<10; ++i) {
        if (i%2 == 0)
            deq.insertFront(i);
        else deq.insertRear(i);
    }

    while(!deq.empty()) {
        std::cout << deq.getFront() << " ";
        deq.deleteFront();
    }
    std::cout << std::endl;

    return 0;
}