//
// Created by Pranay Kamble on 12/09/24.
//
#include <iostream>
#include <stack>

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node (int data) {
        this->data = data;
    }
};

void iterativeInorder(Node *root) { //Time Complexity: O(n), Auxiliary Space: O(height)
    std::stack<Node *> stack;
    Node *curr = root;
    while (curr != nullptr || !stack.empty()) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        std::cout << curr->data << " ";
        curr = curr->right;
    }
}

void free(Node *root) {
    if (root == nullptr) {
        return ;
    }

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->left = new Node(60);
    iterativeInorder(root);

    free(root);
    return 0;
}