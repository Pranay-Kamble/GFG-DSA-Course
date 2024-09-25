//
// Created by Pranay Kamble on 16/09/24.
//
#include <iostream>


class AVLTree{

private:
    class Node {
    public:
        int data;
        Node *left = nullptr, *right = nullptr;
        int height ;
        Node (int data) {
            this->data = data;
            this->height = 0;
        }
    };

    Node *root = nullptr;

public:
    int height(Node *root) {
        if (root == nullptr)
            return 0;   //height is the number of edges from root to the left, we return -1 because no of edges is 1 less than number of nodes

        return root->height;
    }

    int height() {
        return height(this->root);
    }

    Node* rightRotate(Node *root) {
        Node *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;

        root->height = 1 + std::max(height(root->left), height(root->right));
        newRoot->height = 1 + std::max(height(newRoot->left), height(newRoot->right));

        return newRoot;
    }

    Node* leftRotate(Node *root) {
        Node *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;

        root->height = 1 + std::max(height(root->left), height(root->right));
        newRoot->height = 1 + std::max(height(newRoot->left), height(newRoot->right));

        return newRoot;
    }

    Node *rotate(Node* root) {
        if (height(root->left) - height(root->right) > 1) {
            //new insertion in left side, this means left side is unbalanced

            if (height(root->left->left)- height(root->left->right) > 0) {
                //left left case of rotate --> We will just perform one right rotate
                return rightRotate(root);
            }

            if (height(root->left->right) - height(root->left->right) > 0) {
                //left right case of rotate --> we need to first left rotate the grand child, then right rotate the new child
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        if (height(root->right) - height(root->left) > 1) {
            //new insertion in right side, this means right side is unbalanced

            if (height(root->right->right) - height(root->right->left) > 0) {
                //right right case in rotation --> We will just perform one left rotate
                return leftRotate(root);
            }

            if (height(root->right->left) - height(root->right->right) > 0) {
                //right left case in rotation --> We will perform one right rotation on child, then do a left rotate on root
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }


    void insertInBST(int data) {
        this->root =  insertInBST(this->root, data);
    }

    Node* insertInBST(Node *root, int data) {
        if (root == nullptr) {
            root = new Node(data);
            return root;
        }

        if (root->data == data)
            return root;

        if (root->data > data) {
            root->left = insertInBST(root->left, data);
        }else
            root->right = insertInBST(root->right, data);

        root->height = 1 + std::max(height(root->left), height(root->right));
        return rotate(root);
    }

    void free(Node *root) {
        if (root == nullptr)
            return;
        free(root->left);
        free(root->right);
        delete root;
    }

    void free() {
        free(this->root);
    }

    void inorder(Node *root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }

    void inorder() {
        inorder(this->root);
    }

    ~AVLTree() { //destructor
        this->free();
    }
};

int main() {
    AVLTree tree;

    for (int i {}; i<1000; ++i)
        tree.insertInBST(i);

    std::cout << "Height: " << tree.height() << std::endl;

    tree.inorder();
    return 0;
}