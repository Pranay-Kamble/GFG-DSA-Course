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
Node* insertAtEnd(Node* head, int data) {  //Time Complexity = O(n)
    Node* addNode = new Node(data);
    if (head == nullptr) {
        addNode->next = addNode;
        return addNode;
    }
    //Atleast one node is present now
    addNode->next = head;
    Node* curr = head;
    while(curr->next != head) {
        curr = curr->next;
    }
    curr->next = addNode;

    return head;
}
*/

Node* insertAtEnd(Node* head, int data) {  //Time Complexity = O(1)
    if(head == nullptr) {
        Node* add = new Node(data);
        add->next = add;
        return add;
    }
    else {
        Node* add = new Node(head->data);
        add->next = head->next;
        head->next = add;
        head->data = data;
        return add;
    }
}

void printLinkedList(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* curr {head};
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    }while(curr != head);
}
int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    printLinkedList(head);
    return 0;
}