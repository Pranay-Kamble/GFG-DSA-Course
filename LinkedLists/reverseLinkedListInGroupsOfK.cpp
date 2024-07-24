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

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }
    while(head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/*
Node* reverseLinkedListInGroup(Node* head,int k) { //Recursive Solution , Time Complexity = O(n)
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = head->next;
    int count {};
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++count;
    }

    Node* newHead = prev;
    if (curr != nullptr) {
        Node* nextHead = reverseLinkedListInGroup(curr,k);
        head->next = nextHead;
    }
    return newHead;
}
*/

Node* reverseLinkedListInGroup(Node* head, int k) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* prev = nullptr;
    Node* curr = head;
    Node* next =  curr->next;
    bool isFirst {true}; //Used to check if head is fixed or not;

    Node* currTail = nullptr;
    Node* newTail = curr;
    while (curr != nullptr) {
        newTail = curr;
        prev = nullptr;
        int count {};
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++count;
        }

        if (isFirst) {
            head = prev;
            isFirst = false;
        }else {
            currTail->next = prev;
        }
        currTail = newTail;
    }
    return head;
}


Node* insertAtEnd(Node* head, int data) {
    Node* addNode = new Node(data);
    if (head == nullptr) return addNode;

    Node* curr = head;
    while(curr->next != nullptr)
        curr = curr->next;
    curr->next = addNode;
    return head;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    head = insertAtEnd(head,40);
    head = insertAtEnd(head,50);
    head = insertAtEnd(head,60);
    head = insertAtEnd(head,70);
    printLinkedList(head);
    head = reverseLinkedListInGroup(head,3);
    printLinkedList(head);
    return 0;
}