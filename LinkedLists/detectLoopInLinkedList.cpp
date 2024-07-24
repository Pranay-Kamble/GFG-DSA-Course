//
// Created by Pranay Kamble on 17/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node *next = nullptr;

    Node(int data) {
        this->data = data;
    }
};

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
    return head;
}

bool detectLoop(Node* head) {  //Floyd's Detection Algorithm
    Node *fast = head, *slow = head;

    while (fast != nullptr && fast->next != nullptr && fast != slow)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}

