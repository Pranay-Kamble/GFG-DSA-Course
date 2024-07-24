//
// Created by Pranay Kamble on 17/07/24.
//
#include <iostream>

//This is a slight variation to the Floyd's cycle detection algorithm

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void detectAndRemoveLoop(Node* head) {
    Node* fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    if (slow != fast) return;

    slow = head;
    //After sending slow to start, and then moving both fast and slow at same speed they will meet at start of loop
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
}