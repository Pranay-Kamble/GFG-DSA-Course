//
// Created by Pranay Kamble on 18/08/24.
//
#include <iostream>
#include <unordered_map>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

/*
//----------Naive Approach------------ //Time Complexity: O(n*n) [By recursion tree], Space Complexity: O(height)
int height(Node *root) {
    if (root == nullptr) return 0;
    return std::max(height(root->left), height(root->right)) + 1;
}

int diameterOfBinaryTree(Node *root) {
    if (root == nullptr)
        return 0;

    int leftMax = height(root->left);
    int rightMax = height(root->right);

    return (std::max(1+leftMax+rightMax, std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right))));
}
*/

/*
//-------------Better Solution------------//Time Complexity: O(n), Auxiliary Space: O(n)
std::unordered_map<Node *, int> map;

int preComputeHeight(Node *root) {
    if (root == nullptr) {
        map[nullptr] = 0;
        return 0;
    }
    map[root] = 1 + std::max(preComputeHeight(root->left), preComputeHeight(root->right));
    return map[root];
}

int diameterOfBinaryTree(Node *root) {
    if (root == nullptr) return 0;
    preComputeHeight(root);
    return std::max(1 + map[root->left] + map[root->right] , std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}
*/

//-------------Efficient Solution----------

int modifiedHeight(Node *root, int &result) { //
    if (root == nullptr) return 0;
    int leftHeight = modifiedHeight(root->left,result);
    int rightHeight = modifiedHeight(root->right,result);
    result = std::max(result, 1+leftHeight+rightHeight);
    return 1 + std::max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(Node *root) {
    int result = 0;
    modifiedHeight(root,result);
    return result;
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
    root->right->right = new Node(50);
    root->right->left = new Node(40);
    root->right->left->left = new Node(60);
    std::cout << "The diameter of the binary tree is " << diameterOfBinaryTree(root) << std::endl;

    free(root);
    return 0;
}