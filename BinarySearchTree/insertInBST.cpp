//
// Created by Pranay Kamble on 14/09/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;

    Node (int data) {
        this->data = data;
    }
};


Node* recursiveInsertInBST(Node *root, int data) { //Time Complexity: O(height), Space Complexity: O(height), due to recursion call stack
    if (root == nullptr) {
        root = new Node(data);
        return root;
    }
    if (root->data > data) {
        root->left = recursiveInsertInBST(root->left, data);
    }else if (root->data < data) {
        root->right = recursiveInsertInBST(root->right, data);
    }

    return root;
}

Node* iterativeInsertInBST(Node *root, int data) { //Time Complexity: O(height), Auxiliary Space: O(1)
    Node *curr = root;
    Node *prev = nullptr;
    while (curr != nullptr) {
        if (curr->data == data)
            return root;
        prev = curr;
        if (curr->data > data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (prev == nullptr)
        return new Node(data);

    if (prev->data > data)
        prev->left = new Node(data);
    else
        prev->right = new Node(data);

    return root;
}

void inorder(Node *root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = nullptr;
    for (int i {}; i<10; ++i) {
        root = iterativeInsertInBST(root, i);
    }

    inorder(root);
    free(root);
    return 0;
}