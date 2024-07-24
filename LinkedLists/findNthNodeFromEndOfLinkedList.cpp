//
// Created by Pranay Kamble on 16/07/24.
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
    Node* newNode = new Node(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

//---------Naive Approach-------------
/*
void nthNodeFromEnd(Node* head, int n) {    //Time Complexity = O(n)
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }
    if (n <= 0) {
        std::cout << "Invalid Position" << std::endl;
        return ;
    }

    int length{};
    Node* traverser = head;
    while(traverser != nullptr) {
        traverser = traverser->next;
        ++length;
    }
    if (n > length) {
        std::cout << "Position exceeds length" << std::endl;
        return;
    }
    traverser = head;
    for (int i{}; i<length-n; ++i) {
        traverser = traverser->next;
    }
    std::cout << n << " node from end is "<< traverser->data << std::endl;
}
*/

//-------Two-Pointer Approach------------
void nthNodeFromEnd(Node* head, int n) { //Time Complexity = O(n)
    if (head == nullptr) {
        std::cout << "Received nullptr" << std::endl;
        return;
    }
    if (n <= 0) {
        std::cout << "Invalid Position" << std::endl;
        return;
    }

    Node* ptr2 = head;
    for (int i {}; i<n-1 && ptr2 != nullptr; ++i) {
        ptr2 = ptr2->next;
    }
    if (ptr2 == nullptr) {
        std::cout << "Position exceeds length" << std::endl;
        return;
    }

    Node* ptr1 = head;
    while(ptr2->next != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    std::cout << n << " node from end is " << ptr1->data << std::endl;
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
    Node* head {nullptr};
    head = insertAtEnd(head,0);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    head = insertAtEnd(head,40);
    head = insertAtEnd(head,50);
    printLinkedList(head);
    nthNodeFromEnd(head,7);
    return 0;
}