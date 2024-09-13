//
// Created by Pranay Kamble on 19/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};
Node* lowestCommonAncestor(Node *root, int a, int b) {
    if (root == nullptr) return nullptr;
    if (root->data == a || root->data == b) //Current node cannot be the common ancestor
        return root;
    Node *left = lowestCommonAncestor(root->left,a,b); //see if the node we are searching is on left
    Node *right = lowestCommonAncestor(root->right,a,b); // see if searching node is on right
    if (left && right) // if searching nodes are present on the left and right side, then current node is the common ancestor
        return root;
    if (left) return left; //not useful in current call but it useful for previous recursive call
    if (right) return right; //useful for previous recursive calls
    return nullptr;
}

void free(Node *root) {
    if (root == nullptr) return ;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->left->right = new Node(20);
    root->left->right->left = new Node(90);
    root->left->right->left->left = new Node(30);
    root->left->right->right = new Node(80);
    root->left->left = new Node(70);
    root->left->left->left = new Node(40);

    Node *temp = lowestCommonAncestor(root,30,80);
    std::cout <<  temp->data << std::endl;
    free(root);
    return 0;
}