//
// Created by Pranay Kamble on 15/09/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};


int ceilInBST(Node *root, int data) {
    Node *curr = root;
    int result = -1;

    while (curr != nullptr) {
        if (curr->data == data)
            return curr->data;

        if (curr->data > data) {
            result = curr->data;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }

    return result;
}

Node *insertInBST(Node *root, int data) {
    if (root == nullptr)
        return new Node(data);

    if (root->data == data)
        return root;

    if (root->data > data) {
        root->left = insertInBST(root->left, data);
    }else
        root->right = insertInBST(root->right, data);

    return root;
}

void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;
}

void inorder (Node *root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = nullptr;
    root = insertInBST(root, 20);
    root = insertInBST(root, 30);
    root = insertInBST(root,19);
    root = insertInBST(root, 10);
    root = insertInBST(root, 60);
    root = insertInBST(root, 40);
    root = insertInBST(root, 50);
    root = insertInBST(root, 70);
    root = insertInBST(root, 46);
    root = insertInBST(root, 80);
    root = insertInBST(root, 16);

    inorder(root);
    int data = 45;
    std::cout << std::endl << "The ceil of " << data << " is " << ceilInBST(root,data) << std::endl;
    free(root);
    return 0;
}