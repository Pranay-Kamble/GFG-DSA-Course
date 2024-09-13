//
// Created by Pranay Kamble on 12/08/24.
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
//-------------Naive Approach---------------//Time Complexity: O(n), Space Complexity: O(height)
int maxLevel = 0;
void printLeftView(Node *root, int currLevel = 1) {
    if (root == nullptr) return;
    if (currLevel > maxLevel)
        std::cout << root->data << " ";
    maxLevel = std::max(maxLevel,currLevel);
    printLeftView(root->left, currLevel+1);
    printLeftView(root->right, currLevel+1);
}*/

//------------Efficient Approach----------------
void printLeftView(Node *root) { //Time Complexity: O(n), Auxiliary Space: O(width)
    if (root == nullptr) return;
    std::queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) { //Just print the first element of each level using Breadth First Traversal
        int size = queue.size();
        std::cout << queue.front()->data << " ";
        for (int i{}; i<size; ++i) {
            Node* temp = queue.front();
            queue.pop();
            if (temp->left != nullptr) queue.push(temp->left);
            if (temp->right != nullptr) queue.push(temp->right);
        }
    }
}


void free(Node *root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->right->left = new Node(8);
    printLeftView(root);
    free(root);

    return 0;
}