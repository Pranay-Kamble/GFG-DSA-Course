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

// Node* insertAtBegin(Node* head, int data) { //Time Complexity = O(n)
//     Node* newNode {new Node(data)};
//     if (head == nullptr) {
//         newNode->next = newNode;
//     }
//     else{
//         newNode->next = head;
//         Node* curr = head;
//         while (curr->next != head) {  //To reach the last node
//             curr = curr->next;
//         }
//         curr->next = newNode;  //Fixing the next of last node to fix the circular linked list
//     }
//     return newNode;
// }


Node* insertAtBegin(Node* head, int data) { //Time Complexity = O(1), Insert between head and second node, then swap the data
    if (head == nullptr) {
        head = new Node(data);
        head->next = head;
    }
    else {
        Node* add = new Node(head->data);
        add->next = head->next;
        head->next = add;
        head->data = data;
    }
    return head;
}
void printLinkedList(Node* head) {
    if (head == nullptr)
        return;

    //Method-1
    Node* curr {head};
    do{
        std::cout << curr->data << " ";
        curr = curr->next;
    }while (curr != head);
    std::cout << std::endl;
}

int main() {
    Node* head {nullptr};
    head = insertAtBegin(head,0);
    head = insertAtBegin(head,10);
    head = insertAtBegin(head,20);
    head = insertAtBegin(head,30);
    printLinkedList(head);

    return 0;
}
