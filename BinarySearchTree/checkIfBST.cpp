//
// Created by Pranay Kamble on 17/09/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

/*
//-----------------Naive Approach------------------ (Using the leftMax and rightMin method)
int maxValue(Node *root) {
    if (root == nullptr)
        return INT_MIN;

    return std::max(root->data, std::max(maxValue(root->left), maxValue(root->right)));
}

int minValue(Node *root) {
    if (root == nullptr)
        return INT_MAX;

    return std::min(root->data, std::min(minValue(root->left), minValue(root->right)));
}

bool checkIfBST(Node *root) { //Time Complexity: O(n * n), Space Complexity: O(height)
    if (root == nullptr)
        return true;

    int leftMax = maxValue(root->left);
    int rightMin = minValue(root->right);

    if (leftMax < root->data && root->data < rightMin)
        return checkIfBST(root->left) && checkIfBST(root->right);

    return false;
}
*/

/*
//-----------------Efficient Solution -1 -----------------------
bool checkIfBST(Node *root, int left = INT_MIN, int right = INT_MAX) { //Time Complexity: O(n), Space Complexity: O(height)
    if (root == nullptr)
        return true;

    if (left < root->data && root->data < right)
        return checkIfBST(root->left, left, root->data) && checkIfBST(root->right, root->data, right);

    return false;
}*/

//----------------Efficient Solution -2 ------------------------

bool checkIfBST(Node *root, int &prev) { //Time Complexity: O(n), Space Complexity: O(height), similar to inorder traversal
    if (root == nullptr)
        return true;

    if (!checkIfBST(root->left, prev)) //left
        return false;

    if (prev >= root->data) //root
        return false;

    prev = root->data;
    return checkIfBST(root->right, prev); //right
}

Node *insertInBST(Node *root, int data) {
    if (root == nullptr)
        return new Node(data);

    if (root->data == data)
        return root;

    if (root->data > data) {
        root->left = insertInBST(root->left, data);
    }else
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

void inorder(Node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = nullptr;
    root = insertInBST(root, 3);
    root = insertInBST(root, 64);
    root = insertInBST(root, 45);
    root = insertInBST(root, 13);
    root = insertInBST(root, 36);
    root = insertInBST(root, 22);
    root = insertInBST(root, 23);
    root = insertInBST(root, 82);
    // root->data = 63;
    inorder(root);
    int prev = INT_MIN;
    std::cout << std::boolalpha << "\nIs BST? " << checkIfBST(root,prev) << std::endl;
    free(root);
    return 0;
}