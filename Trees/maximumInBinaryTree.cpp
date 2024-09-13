//
// Created by Pranay Kamble on 12/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

int maximumInBinaryTree(Node *root) {
    if (root == nullptr) return INT_MIN;
    return std::max(root->data, std::max(maximumInBinaryTree(root->left), maximumInBinaryTree(root->right)));
}

void free (Node *root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(20);
    root->left->left = new Node(80);
    root->left->left->right = new Node(70);

    std::cout << "The maximum in the binary tree is " << maximumInBinaryTree(root) << std::endl;
    free(root);
    return 0;
}