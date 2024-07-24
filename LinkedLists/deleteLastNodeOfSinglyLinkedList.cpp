//
// Created by Pranay Kamble on 14/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

Node* deleteLastNode(Node* head) {
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* curr {head};
    while(curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
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
    printLinkedList(head);
    std::cout << std::endl;
    head = deleteLastNode(head);
    printLinkedList(head);
}