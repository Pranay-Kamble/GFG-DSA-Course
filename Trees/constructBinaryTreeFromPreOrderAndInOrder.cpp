//
// Created by Pranay Kamble on 15/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

int currNode = 0;
Node* constructBinaryTree(int in[], int pre[], int start, int end) {//Time Complexity: O(n*n), Space Complexity: O(n)
    if (start > end) return nullptr;

    Node *newNode = new Node(pre[currNode++]);

    int index = -1;
    for (int i{start}; i<=end; ++i) {
        if (in[i] == newNode->data) {
            index = i;
            break;
        }
    }
    newNode->left = constructBinaryTree(in,pre,start,index-1);
    newNode->right = constructBinaryTree(in,pre,index+1,end);
    return newNode;
}

void inOrderTraversal(Node *root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void free(Node *root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    int in[] {40,20,50,60,70,10,80,100,30};
    int pre[] {10,20,40,50,60,70,30,80,100};
    Node *root = constructBinaryTree(in,pre,0, std::size(pre)-1);
    inOrderTraversal(root);
    free(root);

    return 0;
}