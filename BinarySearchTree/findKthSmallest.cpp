//
// Created by Pranay Kamble on 17/09/24.
//
#include <iostream>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    int leftCount = 0; //Augmented BST Node
    Node (int data) {
        this->data = data;
    }
};

/*
//-------------Naive Approach-------------------
void kthSmallest(Node *root, int &k) { //Time Complexity: O(height + k), Space Complexity: O(height)
    if (root == nullptr)
        return ;

    kthSmallest(root->left, k);
    --k;
    if (k == 0) {
        std::cout << root->data << std::endl;
        return ;
    }

    kthSmallest(root->right, k);

}*/

//---------------Efficient Approach----------------

Node *insert(Node *root, int data) {
    if (root == nullptr)
        return new Node(data);

    Node *curr = root;
    Node *prev = nullptr;
    while (curr != nullptr) {
        if (curr->data == data)
            return root;
        prev = curr;
        if (curr->data > data) {
            curr->leftCount += 1;
            curr = curr->left;
        }else
            curr = curr->right;
    }

    if (prev->data > data)
        prev->left = new Node(data);
    else
        prev->right = new Node(data);

    return root;
}

int kthSmallest(Node *root, int k) {
    if (root == nullptr)
        return -1;

    Node *curr = root;

    while (curr != nullptr && curr->leftCount +1 != k) {
        if (curr->leftCount+1 > k) {
            curr = curr->left;
        }else {
            k = (k - (curr->leftCount + 1)); //When moving to the right side, we ignore the nodes on the left side, so we
            curr = curr->right;                 // remove them and reduce our search space
        }
    }

    if (curr == nullptr)
        return -1;

    return curr->data;
}


int main() {
    Node *root = nullptr;

    root = insert(root, 3);
    root = insert(root, 15);
    root = insert(root, 83);
    root = insert(root, 34);
    root = insert(root, 56);
    root = insert(root, 33);
    root = insert(root, 13);

    int k = 1;
    printf("The %dth smallest element is %d.\n", k, kthSmallest(root,k));

    return 0;
}