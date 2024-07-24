//
// Created by Pranay Kamble on 12/07/24.
//

class Node {
public:
    int data;
    Node* next = nullptr;
    Node(int data, Node* next);
    Node(int data): Node(data,nullptr){ }
    Node(): Node(0,nullptr){ }
};