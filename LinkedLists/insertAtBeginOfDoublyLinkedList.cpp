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

Node* insertAtBegin(Node* head, int data) {
    Node* start = new Node(data);
    if (head == nullptr) {
        return start;
    }
    start->next = head;
    head->prev = start;
    return start;
}
void printLinkedList(Node* head) {
    Node* traverse = head;
    while(traverse != nullptr) {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }
}
int main() {
    Node* head = nullptr;
    head = insertAtBegin(head,10);
    head = insertAtBegin(head,20);
    head = insertAtBegin(head,30);
    printLinkedList(head);
    return 0;
}