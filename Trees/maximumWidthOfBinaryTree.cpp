//
// Created by Pranay Kamble on 13/08/24.
//

#include <iostream>
#include <queue>

struct Node {
    int data;
    Node *left = nullptr , *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

int maximumWidth(Node *root) { //Time Complexity: O(n), Space Complexity: O(width)
    if (root == nullptr) return 0;
    std::queue<Node *> queue;
    int maxWidth = 1;
    queue.push(root);
    while (!queue.empty()) {
        maxWidth = std::max(maxWidth, static_cast<int>(queue.size()));
        int size = queue.size();
        for (int i {}; i<size; ++i) {
            Node *curr = queue.front();
            queue.pop();
            if (curr->left != nullptr) queue.push(curr->left);
            if (curr->right != nullptr) queue.push(curr->right);
        }
    }
    return maxWidth;
}

void free(Node *root) {
    if (root == nullptr) return;

    free(root->left);
    free(root->right);
    delete root;
}


int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    root->left->left = new Node(40);
    root->left->left->left = new Node(80);

    std::cout << "The maximum width of the binary Tree is " << maximumWidth(root) << std::endl;
    free(root);
    return 0;
}