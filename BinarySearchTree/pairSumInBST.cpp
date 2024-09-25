//
// Created by Pranay Kamble on 19/09/24.
//
#include <iostream>
#include <stack>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void inorder(Node *root, std::vector<int> &vector) {
    if (root == nullptr)
        return;

    inorder(root->left, vector);
    vector.push_back(root->data);
    inorder(root->right, vector);
}

bool pairSumInBST(Node *root, int sum) { //Time Complexity: Theta(n), Auxiliary Space: Theta(n)
    std::vector<int> arr;
    inorder(root, arr);

    int low = 0, high = arr.size()-1;
    while (low < high) {
        if (arr[low] + arr[high] == sum)
            return true;

        if (arr[low] + arr[high] > sum)
            --high;
        else
            ++low;
    }
    return false;
}

Node* insertInBST(Node *root, int data) {
    if (root == nullptr)
        return new Node(data);

    Node *prev = nullptr, *curr = root;

    while (curr != nullptr) {
        if (curr->data == data)
            return root;
        prev = curr;
        if (curr->data > data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (prev->data > data)
        prev->left = new Node(data);
    else
        prev->right = new Node(data);

    return root;
}

void printInorder(Node *root) {
    std::stack<Node *> stack;
    while (root != nullptr || !stack.empty()) {
        while (root != nullptr) {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        std::cout << root->data << " ";
        root = root->right;
    }
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
    // root = insertInBST(root,10);
    root = insertInBST(root,8);
    root = insertInBST(root,20);
    root = insertInBST(root,40);
    root = insertInBST(root,35);
    // root = insertInBST(root,11);
    // root = insertInBST(root,30);
    // root = insertInBST(root,25);

    printInorder(root);
    int sum = 33;
    printf("\nAre there pairs in BST which sum up to %d: %s",sum, pairSumInBST(root, sum) ? "true": "false");

    free(root);
    return 0;
}