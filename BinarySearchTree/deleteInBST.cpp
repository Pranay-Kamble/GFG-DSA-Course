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

Node *deleteInBST(Node *root, int data) { //Time Complexity: O(height), Space Complexity: O(height)
    if (root == nullptr)
        return nullptr;

    if (root->data == data) {
        if (root->left == nullptr && root->right == nullptr) { //Case-1: The node to be deleted is a leaf node
            delete root;
            return nullptr;
        }

        if (root->left == nullptr || root->right == nullptr) { //Case-2: The node to be deleted has 1 child
            Node *left = root->left;
            Node *right = root->right;

            delete root;
            return (left?left:right);
        }

        Node *curr = root->left; //Case-3: The node to be deleted has 2 children
        while (curr->right != nullptr)
            curr = curr->right;  //Finding the inorder predecessor

        root->data = curr->data; //swapping the data
        root->left = deleteInBST(root->left, curr->data); //delete the inorder predecessor and update the root
    }

    else if (root->data > data)
        root->left =  deleteInBST(root->left, data);
    else
        root->right =  deleteInBST(root->right, data);

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

Node* insertInBST(Node *root, int data) {
    Node *curr = root, *prev = nullptr;

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

int main() {
    Node *root = nullptr;
    root = insertInBST(root,39);
    root = insertInBST(root,56);
    root = insertInBST(root,67);
    root = insertInBST(root,38);
    root = insertInBST(root,42);
    root = insertInBST(root,5);
    root = insertInBST(root,32);

    inorder(root);
    std::cout << std::endl;

    root = deleteInBST(root, 5);

    inorder(root);
    free(root);

    return 0;
}