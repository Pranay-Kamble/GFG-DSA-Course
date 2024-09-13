//
// Created by Pranay Kamble on 11/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

/*int heightOfBinaryTree(Node* root, int height = 0) {
    if (root == nullptr) return height;
    return std::max(heightOfBinaryTree(root->left, height+1), heightOfBinaryTree(root->right, height+1));
}*/

int heightOfBinaryTree(Node *root) { //Time Complexity: O(n), Space Complexity: O(height+1);
    if (root == nullptr) return 0;
    return std::max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right)) + 1;
}

void freeMemory(Node *root) {  //Postorder traversal to delete heap memory
    if (root == nullptr) return;
    freeMemory(root->left);
    freeMemory(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node (8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->left = new Node(70);

    std::cout << "The height of the binary Tree is " << heightOfBinaryTree() << std::endl;
    freeMemory(root);
    return 0;
}