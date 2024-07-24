//
// Created by Pranay Kamble on 20/07/24.
//
#include <iostream>
#include <unordered_map>

struct Node {
    int data;
    Node* next = nullptr;
    Node* random = nullptr;
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

bool checkClone(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data || head1->random->data != head2->random->data)
            return false;
    }
    return true;
}

//----------Naive Approach-------------
/*Node* cloneLinkedList(Node* head) {  //Time Complexity = O(n), Space Complexity = O(n)
    std::unordered_map<Node*, Node*> map {};
    Node* curr = head;
    while (curr != nullptr) {
        map[curr] = new Node(curr->data);
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr) {
        map[curr]->next = map[curr->next];
        map[curr]->random = map[curr->random];
        curr = curr->next;
    }

    return map[head];
}*/

Node* cloneLinkedList(Node* head) {  //Time Complexity = O(n), Space Complexity = O(1)
    Node* curr = head;
    while (curr != nullptr) { //Creating clone nodes
        Node* clone = new Node(curr->data);
        clone->next = curr->next;
        curr->next = clone;
        curr = clone->next;
    }

    curr = head;
    Node* newHead = nullptr;
    while (curr != nullptr) {  //Linking the random pointers
        Node* clone = curr->next;

        if (newHead == nullptr)
            newHead = clone;
        clone->random = curr->random == nullptr ? nullptr: curr->random->next;
        curr = clone->next;
    }

    curr = head;
    while (curr != nullptr) {
        Node* clone = curr->next;
        curr->next = clone->next;
        curr = curr->next;
        clone->next = curr == nullptr? nullptr: curr->next;
    }
    return newHead;
}