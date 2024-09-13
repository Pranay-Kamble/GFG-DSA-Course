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

bool childrenSumProperty(Node *root) { //Time Complexity: O(n), Space Complexity: O(height), for recursion call stack
    if (root == nullptr) return true;
    int sum = 0;
    if (root->left == nullptr && root->right == nullptr) //if leaf node is found, it is guaranteed to follow children sum
        return true;

    if (root->left != nullptr) sum += root->left->data;
    if (root->right != nullptr) sum += root->right->data;

    return (sum == root->data) && (childrenSumProperty(root->left) && (childrenSumProperty(root->right)));
}

void free(Node *root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->right->left = new Node(2);
    // root->right->right = new Node(2);
    std::cout << std::boolalpha << childrenSumProperty(root) << std::endl;
    free(root);

    return 0;
}