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
void levelOrderTraversalLineByLine(Node *root) {
    if (root == nullptr) return;
    std::queue<Node*> queue;
    queue.push(root);
    queue.push(nullptr);
    while (queue.size() > 1) {
        Node *temp = queue.front();
        if (temp == nullptr) {
            queue.pop();
            queue.push(nullptr);
            std::cout << "\n";
            continue;
        }
        queue.pop();
        std::cout << temp->data << " ";
        if (temp->left != nullptr) queue.push(temp->left);
        if (temp->right != nullptr) queue.push(temp->right);
    }
}*/

void levelOrderTraversalLineByLine(Node *root) {
    if (root == nullptr) return;
    std::queue<Node*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        for (int i{}; i<size; ++i) {
            Node* temp = queue.front();
            queue.pop();
            std::cout << temp->data <<  " ";
            if (temp->left != nullptr) queue.push(temp->left);
            if (temp->right != nullptr) queue.push(temp->right);
        }
        if (!queue.empty())
            std::cout << '\n';
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
    levelOrderTraversalLineByLine(root);
    freeMemory(root);

    return 0;
}