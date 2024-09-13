//
// Created by Pranay Kamble on 14/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

Node *prev = nullptr;

Node* treeToDLL(Node *root) {  //Time Complexity: O(n), Space Complexity: O(height)
    if (root == nullptr) return root;

    Node *head = treeToDLL(root->left);

    if (prev == nullptr) {
        head = root;
    }else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    treeToDLL(root->right);
    return head;
}

void freeLinkedList(Node *root) {
    if (root == nullptr) return;
    Node *prev = nullptr;
    while (root != nullptr) {
        prev = root;
        root = root->right;
        delete prev;
        prev = root;
    }
}

void displayLinkedList(Node *head) {
    if (head == nullptr) return;
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left  = new Node(30);
    root->right->right  = new Node(35);
    Node *head = treeToDLL(root);
    displayLinkedList(head);
    free(root);

    return 0;
}