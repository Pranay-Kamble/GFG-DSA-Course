//
// Created by Pranay Kamble on 11/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

/*void printKthNode(Node *root, int k, int level = 0) {
    if (root == nullptr || level > k)
        return;
    if (level == k) {
        std::cout << root->data << " ";
        return;
    }
    printKthNode(root->left,k,level+1);
    printKthNode(root->right,k,level+1);
}*/

void printKthNode(Node *root, int k) {
    if (root == nullptr)
        return;
    if (k == 0) {
        std::cout << root->data << " ";
        return;
    }
    printKthNode(root->left, k-1);
    printKthNode(root->right, k-1);
}

void freeMemory(Node *root) {
    if (root == nullptr) return;
    freeMemory(root->left);
    freeMemory(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->right = new Node(70);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    printKthNode(root,2);
    freeMemory(root);

    return 0;
}