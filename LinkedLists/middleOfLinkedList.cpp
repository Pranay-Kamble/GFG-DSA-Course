//
// Created by Pranay Kamble on 15/07/24.
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
    if (head == nullptr) return new Node(data);

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = new Node(data);
    return head;
}

int middleOfLinkedList(Node* head) {
    if (head == nullptr) {
        return -1;
    }
    Node* fast = head; //moves 2 position
    Node* slow = head; //moves 1 position -> will reach middle when fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
    }
    do {
        std::cout << head->data << " ";
        head = head->next;
    }while (head != nullptr);
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,5);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,15);
    head = insertAtEnd(head,25);
    head = insertAtEnd(head,30);
    printLinkedList(head);
    std::cout << "The middle of the LinkedList is " << middleOfLinkedList(head);
}