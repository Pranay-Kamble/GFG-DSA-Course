//
// Created by Pranay Kamble on 13/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node(int data) {
        this -> data = data;
    }
};

void printLinkedListRecursive(Node* head) {
    if (head == nullptr)  //Time Complexity = O(n), Space Complexity = O(n)
        return;
    std::cout << head->data << " ";
    printLinkedListRecursive(head->next);
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printLinkedListRecursive(head);
}