//
// Created by Pranay Kamble on 16/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node *next = nullptr;

    Node(int data) {
        this->data = data;
    }
};

void removeDuplicatesFromSorted(Node* head) {  //Kept as void because head will never be changed
    if (head == nullptr || head->next == nullptr)
        return ;

    Node* ans = head;
    while (head->next != nullptr) {
        if (head->data == head->next->data) {
            Node* deleteNode = head->next;
            head->next = head->next->next;
            delete deleteNode;
        }
        else {
            head = head->next;
        }
    }
}

Node* insertAtEnd(Node* head, int data) {
    Node* addNode = new Node(data);
    if (head == nullptr)
        return addNode;

    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = addNode;
    return head;
}

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
    }else {
        while (head != nullptr) {
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,0);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,40);
    printLinkedList(head);
    removeDuplicatesFromSorted(head);
    printLinkedList(head);
}