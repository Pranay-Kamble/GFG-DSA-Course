//
// Created by Pranay Kamble on 23/07/24.
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
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/*
//-----------My Approach--------(without tail pointer)
Node* mergeSorted(Node* head1, Node* head2) {
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node* result = head1->data <= head2->data ? head1 : head2;

    Node *curr1 = head1, *prev1 = nullptr, *next1 = curr1->next;
    Node *curr2 = head2, *next2 = head2->next;

    while (curr1 != nullptr && curr2 != nullptr) {
        next1 = curr1->next;
        next2 = curr2->next;
        if (curr1->data <= curr2->data) {
            prev1 = curr1;
            if (next1 == nullptr) {
                curr1->next = curr2;
            }
            curr1 = next1;
        } else {
            if (prev1 != nullptr)
                prev1->next = curr2;
            curr2->next = curr1;
            prev1 = curr2;
            curr2 = next2;
        }
    }
    return result;
}*/

Node* mergeSorted(Node* head1, Node* head2) { //Time Complexity = O(m+n)
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    Node *a = head1, *b = head2;
    Node *head = nullptr, *tail = head;
    if (a->data <= b->data) {
        head = tail = a;
        a = a->next;
    }else {
        head = tail = b;
        b = b->next;
    }
    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        }else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a == nullptr)
        tail->next = b;
    else
        tail->next = a;
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
    Node* head1 = nullptr;
    head1 = insertAtEnd(head1,5);
    head1 = insertAtEnd(head1,10);
    head1 = insertAtEnd(head1,15);
    head1 = insertAtEnd(head1,40);
    Node* head2 = nullptr;
    head2 = insertAtEnd(head2,2);
    head2 = insertAtEnd(head2,3);
    head2 = insertAtEnd(head2,20);
    // head2 = insertAtEnd(head2,18);
    // head2 = insertAtEnd(head2,35);
    printLinkedList(head1);
    printLinkedList(head2);
    Node* head = mergeSorted(head1,head2);
    printLinkedList(head);
    return 0;
}