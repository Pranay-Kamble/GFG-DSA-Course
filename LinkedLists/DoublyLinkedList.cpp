//
// Created by Pranay Kamble on 14/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node (int data) {
        this -> data = data;
    }
};

int main() {
    Node* head = new Node(0);
    Node* first = new Node(1);
    Node* second = new Node(2);
    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;
}