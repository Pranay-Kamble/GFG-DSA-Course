//
// Created by Pranay Kamble on 20/08/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

int result = 0;

int burnTimeFromLeaf(Node *root, int leaf, int &distance) {
    if (root == nullptr) return 0;
    if (root->data == leaf) {
        distance = 0;  //indicates to upper recursive calls that leaf node has been found
        return 1;  //returning 1 to show height function behaviour
    }
    int leftDistance = -1, rightDistance = -1;
    int leftHeight = burnTimeFromLeaf(root->left, leaf, leftDistance);
    int rightHeight = burnTimeFromLeaf(root->right, leaf, rightDistance);
    if (leftDistance != -1) { //we have found the required leaf on left side
        distance = leftDistance + 1; //propagate the distance we got from lower recursive calls to upper nodes
        result = std::max(result, distance + rightHeight);
    }
    if (rightDistance != -1) {//we have found the required leaf on the right side
        distance = rightDistance + 1;
        result = std::max(result, distance + leftHeight);
    }
    return 1 + std::max(leftHeight, rightHeight); //normal height function behaviour
}

void free(Node *root) {
    if (root == nullptr) return ;
    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(50);
    root->left->left = new Node(40);
    root->left->left->left = new Node(60);
    root->left->left->left->left = new Node(70);
    int dist = 0;
    burnTimeFromLeaf(root,50,dist);
    std::cout << "Burn Time: " << result << std::endl;

    free(root);
    return 0;
}