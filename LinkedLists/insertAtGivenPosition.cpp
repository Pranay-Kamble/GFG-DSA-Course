//
// Created by Pranay Kamble on 14/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node(int data) {
        this->data = data;
    }
};

Node* insertAtPosition(Node* head, int data, int position) {
    Node* insert = new Node(data);
    if (position == 1) {
        insert->next = head;
        return insert;
    }
    Node* currPtr {head};
    for (int i{1}; i<=position-2 && currPtr != nullptr; ++i) {
        currPtr = currPtr->next;
    }

    if (currPtr == nullptr)
        return head;
    insert->next = currPtr->next;
    currPtr->next = insert;
    return head;
}

void printLinkedList(Node* head) { //head variable is copied and is not same as the one in main()
    Node* traverse = head;
    while(traverse != nullptr) {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head = insertAtPosition(head,0,10);
    printLinkedList(head);
}