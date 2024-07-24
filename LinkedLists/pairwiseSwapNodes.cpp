//
// Created by Pranay Kamble on 19/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/*-------Naive Solution----------(because it swaps two data types, it will become inefficient if data types are custom classes)
void pairwiseSwapNodes(Node* head) { //Time Complexity = O(n), Space Complexity = O(1)

    Node* curr = head;
    while (curr!=nullptr && curr->next!=nullptr) {
        std::swap(curr->data,curr->next->data);
        curr = curr->next->next;
    }
}*/

//---------Efficient Solution---------(Changes the pointers)
Node* pairwiseSwapNodes(Node* head) { //Time Complexity = O(n), Space Complexity = O(1)
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *prev = nullptr, *curr = head, *next = curr->next->next;
    head = head->next; //It is guaranteed that second element will become head, as it will swap to first position

    while (curr != nullptr && curr->next != nullptr) {
        next = curr->next->next;
        if (prev != nullptr)
            prev->next = curr->next;
        curr->next->next = curr;
        curr->next = next;
        prev = curr;
        curr = curr->next;
    }

    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr)
        return newNode;

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = newNode;
    return head;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,0);
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);
    // head = insertAtEnd(head,60);
    // head = insertAtEnd(head,70);
    printLinkedList(head);
    head = pairwiseSwapNodes(head);
    printLinkedList(head);
    return 0;
}