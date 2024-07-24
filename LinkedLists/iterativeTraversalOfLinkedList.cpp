//
// Created by Pranay Kamble on 13/07/24.
//

#include <iostream>

struct Node {
    int data {};
    Node* next = nullptr;

    Node(int data) {
        this->data = data;
    }
};

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
    printLinkedList(head);
}