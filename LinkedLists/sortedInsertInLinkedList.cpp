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

/*
 //By Using two pointer two consecutive nodes
Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) return newNode;

    Node* ptr1 {head};
    Node* ptr2 {head->next};

    if (ptr2 == nullptr || ptr1->data > data) {  //Means only single node is present
        if (ptr1->data <= data) {
            head->next = newNode;
            return head;
        }

        newNode->next = head;
        return newNode;
    }

    while(ptr2 != nullptr && ptr2->data <= data) {
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }
    if (ptr2 != nullptr)
        newNode->next = ptr2;
    ptr1->next = newNode;
    return head;
}*/

Node* sortedInsert(Node* head, int data) {
    Node* add = new Node(data);
    if (head == nullptr) return add;
    if (head->data > data) {
        add->next = head;
        return add;
    }

    Node* curr = head;
    while(curr->next != nullptr && curr->next->data <= data)
        curr = curr->next;

    add->next = curr->next;
    curr->next = add;
    return head;
}


void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }
    do {
        std::cout << head->data << " ";
        head = head->next;
    }while(head != nullptr);
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    printLinkedList(head);
    head = sortedInsert(head,0);
    printLinkedList(head);
    head = sortedInsert(head,10);
    printLinkedList(head);
    head = sortedInsert(head,20);
    printLinkedList(head);
    head = sortedInsert(head,30);
    printLinkedList(head);
    head = sortedInsert(head,5);
    printLinkedList(head);
    head = sortedInsert(head,25);
    printLinkedList(head);

    return 0;
}