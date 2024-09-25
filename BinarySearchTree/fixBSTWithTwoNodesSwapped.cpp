//
// Created by Pranay Kamble on 18/09/24.
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
//-----------------Naive Solution-------------------
void inorder(Node *root, std::vector<Node *> &vector) {
    if (root == nullptr)
        return;

    inorder(root->left, vector);
    vector.push_back(root);
    inorder(root->right, vector);
}

Node *fixBSTWithSwappedNodes(Node *root) { //Time Complexity: O(n), Auxiliary Space: O(n)
    std::vector<Node *> vector ;
    inorder(root,vector);

    int index1 = -1, index2 = -1;

    for (int i {}; i<vector.size()-1; ++i) {
        if (vector[i]->data > vector[i+1]->data) {
            if (index1 == -1)
                index1 = i;
            index2 = i+1;
        }
    }
    std::swap(vector[index1]->data, vector[index2]->data);

    return root;
}

*/

//--------------------Efficient Solution---------------------
void helper(Node *root, Node *&prev, Node *&first, Node *&second) { //Time Complexity: O(n), Space Complexitu: O(height)

    if (root == nullptr) {
        return ;
    }
    helper(root->left, prev, first, second);

    if (prev != nullptr && root->data < prev->data) {
        if (first == nullptr) //If we find the first violation then we set them to adjacent nodes
            first = prev;
        second = root; //If it reaches second time then first will not be updated and only second is changed
    }
    prev = root;

    helper(root->right, prev, first, second);

}

Node *fixBSTWithSwappedNodes(Node *root) {
    Node *prev = nullptr, *first = nullptr, *second = nullptr;
    helper(root, prev,first, second);

    std::swap(first->data, second->data);

    return root;
}
void printInorder(Node *root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    std::cout << root->data << " ";
    printInorder(root->right);
}

Node* insertInBST(Node *root, int data) {
    if (root == nullptr)
        return new Node(data);

    Node *curr = root, *prev = nullptr;

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

void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = nullptr;
    // root = insertInBST(root, 4);
    // root = insertInBST(root, 46);
    // root = insertInBST(root, 44);
    // root = insertInBST(root, 43);
    // root = insertInBST(root, 54);
    // root = insertInBST(root, 23);
    // root = insertInBST(root, 33);
    // root = insertInBST(root, 36);
    // root = insertInBST(root, 65);
    // root = insertInBST(root, 74);
    // root = insertInBST(root, 25);
    // root = insertInBST(root, 46);
    // root = insertInBST(root, 75);

    root = new Node(60);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(10);

    root->right = new Node(80);
    root->right->right = new Node(100);
    root->right->left = new Node(20);

    root = fixBSTWithSwappedNodes(root);

    printInorder(root);
    free(root);
    return 0;
}