//
// Created by Pranay Kamble on 17/08/24.
//
#include <iostream>
#include <deque>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void spiralTraversal(Node *root) {  //Time Complexity: O(n), Auxiliary Space: O(n)
    if (root == nullptr) return;
    bool level = false;
    std::deque<Node *> deque;
    deque.push_back(root);
    while (!deque.empty()) {
        int size = deque.size();
        Node *curr = nullptr;
        if (level) {
            for (int i{}; i<size; ++i) {
                curr = deque.back();
                std::cout << deque.back()->data << " ";
                deque.pop_back();
                if (curr->right != nullptr) deque.push_front(curr->right);
                if (curr->left != nullptr) deque.push_front(curr->left);
            }
        }
        else {
            for (int i{}; i<size; ++i){
                curr = deque.front();
                deque.pop_front();
                std::cout << curr->data << " ";
                if (curr->left != nullptr) deque.push_back(curr->left);
                if (curr->right != nullptr) deque.push_back(curr->right);
            }
        }
        level = !level;
    }
}

void free(Node *root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(10);
    root->right->right = new Node(7);
    spiralTraversal(root);
    free(root);
    return 0;
}