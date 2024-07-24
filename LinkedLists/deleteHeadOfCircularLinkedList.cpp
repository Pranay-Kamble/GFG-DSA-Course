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

/*Node* deleteHead(Node* head) { //Time Complexity = O(n)
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    Node* last {head};
    while(last->next != head) {
        last = last->next;
    }
    last->next = head->next;
    delete head;
    return last->next;
}*/

Node* deleteHead(Node* head) { //Time Complexity = O(1)
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
    head = deleteHead(head);
    head = deleteHead(head);
    printLinkedList(head);
    return 0;
}