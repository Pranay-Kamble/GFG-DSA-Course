//
// Created by Pranay Kamble on 18/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return ;
    }

    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteNode(Node* del) {
    if (del == nullptr || del->next == nullptr) {
        del = nullptr;
        return;
    }

    Node* deleteNode = del->next;
    del->data = del->next->data;
    del->next = del->next->next;
    delete deleteNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr)
        return newNode;

    Node* last = head;
    while (last->next != nullptr)
        last = last->next;
    last->next = newNode;

    return head;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,0);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    head = insertAtEnd(head,40);
    head = insertAtEnd(head,50);
    head = insertAtEnd(head,60);
    head = insertAtEnd(head,70);
    head = insertAtEnd(head,80);
    printLinkedList(head);
    deleteNode(head->next->next->next->next->next->next->next->next);
    printLinkedList(head);
    return 0;
}