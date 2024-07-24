//
// Created by Pranay Kamble on 14/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int data) {
        this->data = data;
    }
};

Node* deleteHead(Node* head) {
    if(head == nullptr)
        return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    head->next->prev = nullptr;
    Node* ans {head->next};
    delete head;
    return ans;
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
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    printLinkedList(head);
    std::cout << std::endl;
    head = deleteHead(head);
    printLinkedList(head);
}