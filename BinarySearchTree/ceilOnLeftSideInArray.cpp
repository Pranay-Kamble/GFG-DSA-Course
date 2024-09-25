//
// Created by Pranay Kamble on 17/09/24.
//
#include "avlTree.h"
#include <iostream>
#include <vector>


int ceiling(Node *root, int data) {
    int result = -1;
    while (root != nullptr) {
        if (root->data == data)
            return root->data;

        if (root->data > data) {
            result = root->data;
            root = root->left;
        }else if (root->data < data)
            root = root->right;
    }

    return result;
}

void ceilOnLeft(const std::vector<int> &arr) {
    AVLTree tree;
    std::cout << "-1 ";
    tree.insert(arr[0]);

    for (int i {1}; i<arr.size(); ++i) {
        int ceil = ceiling(tree.getRoot(), arr[i]);

        std::cout << ceil << " ";
        tree.insert(arr[i]);
    }

}

int main() {
    std::vector<int> arr = {2,8,30,15,25,12};
    ceilOnLeft(arr);

    return 0;
}