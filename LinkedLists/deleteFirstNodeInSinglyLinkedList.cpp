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


Node* deleteFirstNode(Node* head) {
    if (head == nullptr)
        return nullptr;
    Node* newHead = head->next;
    delete head;  //Deallocating the memory
    return newHead;
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
    head = deleteFirstNode(head);
    printLinkedList(head);
}