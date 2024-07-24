//
// Created by Pranay Kamble on 15/07/24.
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

Node* insertAtBegin(Node* head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        newNode->prev = newNode->next = newNode;
        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    newNode->prev->next = newNode;

    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        newNode->next = newNode->prev = newNode;
        return newNode;
    }

    newNode->prev = head->prev;
    head->prev = newNode;
    newNode->next = head;
    newNode->prev->next = newNode;

    return head;
}

void printLinkedList(Node* head) {
    if (head == nullptr)
        std::cout << nullptr << std::endl;
    Node* traverse = head;
    do {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }while (traverse != head);
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,0);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    printLinkedList(head);
    return 0;
}