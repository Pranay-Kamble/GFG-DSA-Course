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

Node* insertAtEnd(Node* head, int data) {
    Node* end = new Node(data);
    if (head == nullptr) {
        return end;
    }
    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = end;
    return head;
}

void printLinkedList(Node* head) {
    while(head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,0);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    head = insertAtEnd(head,40);
    printLinkedList(head);
}