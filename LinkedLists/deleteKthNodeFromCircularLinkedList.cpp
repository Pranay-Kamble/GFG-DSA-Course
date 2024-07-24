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


Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    head->data = head->next->data;
    Node* temp = head->next->next;
    delete head->next;
    head->next = temp;
    return head;
}

Node* deleteKthNode(Node* head, int k) {
    //deletes Kth node from head , assuming 1-based indexing and k <= size(n)
    if (head == nullptr) return nullptr;
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    if (k == 1)
        return deleteHead(head);
    Node* curr = head;
    for (int i {1}; i<k-1 ; ++i) {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }

    Node* curr = head;
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    while(curr != head);
}

int main() {
    Node* head = new Node(0);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = head;
    printLinkedList(head);
    std::cout << std::endl;
    head = deleteKthNode(head,3);
    printLinkedList(head);
    return 0;
}