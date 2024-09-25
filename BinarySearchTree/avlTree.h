//
// Created by Pranay Kamble on 17/09/24.
//

#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "node.h"

class AVLTree {
private:
    Node *root = nullptr;
public:
    Node *getRoot() {
        return this->root;
    }
    Node* insert(Node *root, int data) {
         if (root == nullptr) {
             return new Node(data);
         }

         if (root->data == data)
             return root;

         if (root->data > data)
             root->left = insert(root->left, data);
         else
             root->right = insert(root->right, data);

         root->height = 1 + std::max(height(root->left), height(root->right));

         return rotate(root);
    }

    void insert(int data) {
        this->root = insert(this->root, data);
    }

    int height(Node *root) {
         if (root == nullptr)
             return 0;

         return root->height;
    }

    int height() {
        return height(this->root);
    }

    Node *rotate(Node *root) {
         if (height(root->left) - height(root->right) > 1) {
             //left side insert occurred

             if (height(root->left->left) - height(root->left->right) > 0) {
                 //left left case in rotation
                 return rightRotate(root);
             }

             if (height(root->left->right) - height(root->left->left) > 0) {
                 root->left = leftRotate(root->left);
                 return rightRotate(root);
             }
         }

         if (height(root->right) - height(root->left) > 1) {
             //right side insert occurred
             if (height(root->right->right) - height(root->right->left) > 0) {
                 //right right case
                 return leftRotate(root);
             }

             if (height(root->right->left) - height(root->right->right) > 0) {
                 //right left case
                 root->right = rightRotate(root->right);
                 return leftRotate(root);
             }
         }

         return root;
    }


    Node *rightRotate(Node *root) {
         Node *newRoot = root->left;
         root->left = newRoot->right;
         newRoot->right = root;

         root->height = 1 + std::max(height(root->left), height(root->right));
         newRoot->height = 1 + std::max(height(newRoot->left), height(newRoot->right));

         return newRoot;
    }

    Node *leftRotate(Node *root) {
         Node *newRoot = root->right;
         root->right = newRoot->left;
         newRoot->left = root;

         root->height = 1 + std::max(height(root->left), height(root->right));
         newRoot->height = 1 + std::max(height(newRoot->left), height(root->right));

         return newRoot;
    }

    static void inOrder(Node *root) {
         if (root == nullptr)
             return;

         inOrder(root->left);
         std::cout << root->data << " ";
         inOrder(root->right);
    }

    static void postOrder(Node *root) {
         if (root == nullptr)
             return;
         postOrder(root->left);
         postOrder(root->right);
         std::cout << root->data << " ";
    }

    static void preOrder(Node *root){
         if (root == nullptr)
             return;
         std::cout << root->data << " ";
         preOrder(root->left);
         preOrder(root->right);
    }

    void inorder() {
        inOrder(this->root);
    }
    void preorder() {
        preOrder(this->root);
    }
    void postorder() {
        postOrder(this->root);
    }

    void free(Node *root) {
        if (root == nullptr)
            return;

        free(root->left);
        free(root->right);
        delete root;
    }

    ~AVLTree() {
        free(this->root);
    }

 };
#endif //AVLTREE_H
