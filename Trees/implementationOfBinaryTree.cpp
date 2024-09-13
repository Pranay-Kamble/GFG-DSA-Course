//
// Created by Pranay Kamble on 10/08/24.
//
#include <iostream>

struct Node {
    Node *left = nullptr, *right = nullptr;
    int key;
    Node(int data) {
        this->key = data;
    }
};

