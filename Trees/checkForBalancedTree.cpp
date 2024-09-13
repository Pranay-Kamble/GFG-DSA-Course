//
// Created by Pranay Kamble on 13/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};


/*
//-------------Naive Solution--------------
int height(Node *root) {
    if (root == nullptr) return 0;
    return (std::max(height(root->left), height(root->right))) + 1;
}

bool isBalanced(Node *root) { //Time Complexity: O(n*n), Space Complexity: O(
    if (root == nullptr) return true;
    int left = height(root->left);
    int right = height(root->right);

    return abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
*/

int isBalanced(Node *root) { //Time Complexity: O(n), Space Complexity: O(height)
    if (root == nullptr) return 0;

    int lHeight = isBalanced(root->left);
    if (lHeight == -1) return -1;
    int rHeight = isBalanced(root->right);
    if (rHeight == -1) return -1;

    if (abs(lHeight - rHeight) > 1) return -1;
    return (std::max(lHeight,rHeight)) + 1;
}

void free(Node *root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(18);
    root->left = new Node(4);
    root->left->left = new Node(5);
    root->left->right = new Node(9);
    root->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->left = new Node(6);

    std::cout << std::boolalpha << isBalanced(root) << std::endl;
    free(root);
    return 0;
}