//
// Created by Pranay Kamble on 19/09/24.
//
#include <iostream>
#include <map>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void verticalSumHelper(Node *root, std::map<int, int> &map, int horizontal = 0) {
    if (root == nullptr)
        return;

    verticalSumHelper(root->left, map, horizontal-1);
    map[horizontal] += root->data;
    verticalSumHelper(root->right, map, horizontal+1);
}

void verticalSumOfBST(Node *root) {
    std::map<int,int> map;

    verticalSumHelper(root, map);

    for (std::map<int,int>::iterator i = map.begin(); i!=map.end(); ++i) {
        std::cout << i->first << " " << i->second << "\n";
    }
}

void inorder(Node *root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

Node* insertInBST(Node *root, int data) {
    if (root == nullptr)
        return new Node(data);

    if (root->data == data)
        return root;

    if (root->data > data)
        root->left = insertInBST(root->left, data);
    else
        root->right = insertInBST(root->right, data);

    return root;
}

void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = nullptr;

    root = insertInBST(root,10);
    root = insertInBST(root,15);
    root = insertInBST(root,25);
    root = insertInBST(root,35);
    root = insertInBST(root,20);
    root = insertInBST(root,75);
    root = insertInBST(root,80);
    root = insertInBST(root,40);
    inorder(root);

    std::cout << std::endl;
    verticalSumOfBST(root);

    free(root);
    return 0;
}