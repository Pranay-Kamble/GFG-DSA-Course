//
// Created by Pranay Kamble on 12/09/24.
//
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node (int data) {
        this->data = data;
    }
};

void serialize(Node *root, std::vector<int> &vector) { //Time Complexity: O(n), Space Complexity: O(height)
    if (root == nullptr) {
        vector.push_back(-1);
        return ;
    }

    vector.push_back(root->data);
    serialize(root->left, vector);
    serialize(root->right, vector);
}

Node *deSerialize(const std::vector<int> &vector, int &index) { //Time Complexity: O(n), Space Complexity: O(height)
    // if (index >= vector.size()) {
    //     return nullptr;
    // }

    if (vector[index] == -1) {
        ++index;
        return nullptr;
    }
    Node *root = new Node(vector[index++]);

    root->left = deSerialize(vector, index);
    root->right = deSerialize(vector, index);

    return root;
}

void preorder(Node *root) {
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->left->right = new Node(40);

    std::vector<int> serialized;
    serialize(root, serialized);

    for (int i: serialized) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int index = 0;
    Node *test = deSerialize(serialized,index);
    preorder(test);

    free(root);
    free(test);
    return 0;
}
