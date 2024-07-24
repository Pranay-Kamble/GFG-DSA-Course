//
// Created by Pranay Kamble on 14/07/24.
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

Node* insertAtEnd(Node* head, int data) {
    Node* end = new Node(data);
    if (head == nullptr) {
        return end;
    }
    Node* ptr {head};
    while(ptr->next != nullptr) {
        ptr = ptr->next;
    }

    ptr->next = end;
    end->prev = ptr;
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
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    printLinkedList(head);
    return 0;
}