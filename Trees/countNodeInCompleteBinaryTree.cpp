//
// Created by Pranay Kamble on 12/09/24.
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

//---------------Naive Method------------------
// void countNodes(Node *root, int &count) { //Time Complexity: O(n), Space Complexity: O(height)
//     if (root == nullptr) {
//         return;
//     }
//     ++count;
//
//     countNodes(root->left,count);
//     countNodes(root->right,count);
// }


//----------------Efficient Method-------------
int leftHeight (Node *root) {
    Node *curr = root;
    int leftHeight = 0;
    while (curr != nullptr) {
        ++leftHeight;
        curr = curr->left;
    }
    return leftHeight;
}

int rightHeight(Node *root) {
    Node *curr = root;
    int rightHeight = 0;
    while (curr != nullptr) {
        ++rightHeight;
        curr = curr->right;
    }
    return rightHeight;
}

int countNodes(Node *root) { //Time Complexity: O(logn * logn), Space Complexity: O(height)
    if (root == nullptr)
        return 0;

    int left = leftHeight(root);
    int right = rightHeight(root);

    if (left == right)
        return pow(2,left) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
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
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    std::cout << "The number of nodes: " << countNodes(root) << std::endl;
    free(root);
    return 0;
}