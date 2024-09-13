//
// Created by Pranay Kamble on 11/08/24.
//
#include <iostream>
#include <queue>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

/*
//---------Naive Solution------------//Time Complexity: O(height + (n * height)) = O(n*height), Space Complexity: O(n)
int heightOfBinaryTree(Node *root) {
    if (root == nullptr) return 0;
    return std::max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right)) + 1;
}
void printKthElement(Node *root, int k) {
    if (root == nullptr) return;
    if (k == 0) {
        std::cout << root->data << " ";
        return;
    }
    printKthElement(root->left,k-1);
    printKthElement(root->right, k-1);
}
void levelOrderTraversal(Node *root) {
    for (int i {}; i<=heightOfBinaryTree(root); ++i) {
        printKthElement(root,i);
    }
}
*/


//------------Efficient Approach-----------------
void levelOrderTraversal(Node *root) {
    if (root == nullptr) {
        std::cout << "Empty Tree" << std::endl;
        return;
    }
    std::queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node *temp = queue.front();
        std::cout << queue.front()->data << " ";
        queue.pop();
        if (temp->left != nullptr)
            queue.push(temp->left);
        if (temp->right != nullptr)
            queue.push(temp->right);
    }
}


void freeMemory(Node *root) {
    if (root == nullptr) return;
    freeMemory(root->left);
    freeMemory(root->right);
    delete root;
}

int main() {
    Node *root = new Node(3);
    root->left = new Node(4);
    root->left->right = new Node(5);
    levelOrderTraversal(root);
    freeMemory(root);

    return 0;
}