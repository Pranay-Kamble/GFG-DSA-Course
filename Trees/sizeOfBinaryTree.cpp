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

int sizeOfBinaryTree(Node *root) {  //Time Complexity: O(n), Space Complexity: O(height)
    if (root == nullptr) return 0;

   return 1 + sizeOfBinaryTree(root->left) + sizeOfBinaryTree(root->right);
}

void free(Node *root) {
    if (root == nullptr) return ;

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    std::cout << "The size of the binary Tree is " << sizeOfBinaryTree(root) << std::endl;
    free(root);

    return 0;
}