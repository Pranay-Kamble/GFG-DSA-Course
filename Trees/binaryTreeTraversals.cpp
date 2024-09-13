//
// Created by Pranay Kamble on 10/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void inOrderTraversal(Node* root) { //Time Complexity: O(number of nodes ), Space Complexity: O(height of the tree)
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}


void freeMemoryLeak(Node* root) { //Just to prevent memory leak. Slight variation of postorder traversal
    if (root == nullptr) return;
    freeMemoryLeak(root->left);
    freeMemoryLeak(root->right);
    delete root;
}
int main() {
    Node *root = nullptr;
    root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    inOrderTraversal(root);
    std::cout << std::endl;
    preOrderTraversal(root);
    std::cout << std::endl;
    postOrderTraversal(root);
    std::cout << std::endl;

    freeMemoryLeak(root);
    return 0;
}