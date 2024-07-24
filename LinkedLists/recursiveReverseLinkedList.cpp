//
// Created by Pranay Kamble on 16/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node *next = nullptr;

    Node(int data) {
        this->data = data;
    }
};

Node* insertAtBegin(Node* head, int data) {
    Node* newHead = new Node(data);
    newHead->next = head;
    return newHead;
}


/*
//-------Method-1----------
Node* recursiveReverse(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* newHead = recursiveReverse(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next = nullptr;

    return newHead;
}*/

//---------Method-2---------
Node* recursiveReverse(Node* head, Node* prev = nullptr) {
    if (head == nullptr)
        return prev;

    Node* temp = head->next;
    head->next = prev;
    return recursiveReverse(temp,head);
}

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }

    while(head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtBegin(head,0);
    head = insertAtBegin(head,10);
    head = insertAtBegin(head,20);
    head = insertAtBegin(head,30);
    head = insertAtBegin(head,40);
    head = insertAtBegin(head,50);
    printLinkedList(head);
    head = recursiveReverse(head);
    printLinkedList(head);
}
