//
// Created by Pranay Kamble on 13/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;

    Node (int data) {
        this->data = data;
    }
};

Node* insertAtBegin(Node* head, int data) {
    Node* begin = new Node(data);
    begin->next = head;
    return begin;
}

void insertAtBegin(Node** headPtr, int data) {
    Node* newNode = new Node(data);
    newNode->next = *headPtr;
    *headPtr = newNode;
}

void printLinkedList(Node* head) {
    while(head != nullptr) {
        std::cout << head->data << ' ';
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    head = insertAtBegin(head,40);
    head = insertAtBegin(head,30);
    head = insertAtBegin(head,20);
    head = insertAtBegin(head,10);
    head = insertAtBegin(head,0);
    printLinkedList(head);
}