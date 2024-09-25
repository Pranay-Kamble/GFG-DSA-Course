//
// Created by Pranay Kamble on 13/09/24.
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

bool recursiveSearchInBST(Node *root, int data) { //Time Complexity: O(height), Space Complexity: O(height)
    if (root == nullptr)
        return false;
    if (root->data == data)
        return true;
    if (root->data > data)
        return recursiveSearchInBST(root->left, data);
    return recursiveSearchInBST(root->right, data);
}

bool iterativeSearchInBST(Node *root, int data) { //Time Complexity: O(log n), Auxiliary Space: O(1)
    if (root == nullptr)
        return false;

    Node *curr = root;
    while (curr != nullptr) {
        if (curr->data == data)
            return true;
        if (root->data > data)
            curr = root->left;
        else
            curr = root->right;
    }
    return false;
}
void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;

}

int main() {
    Node *root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(4);
    root->right = new Node(30);
    root->right->right = new Node(50);
    int data = 10;

    printf("Is %d present in the BST?: %s", data, iterativeSearchInBST(root,data) ? "true": "false");
    free(root);
    return 0;
}