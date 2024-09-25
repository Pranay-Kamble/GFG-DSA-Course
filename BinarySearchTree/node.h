//
// Created by Pranay Kamble on 17/09/24.
//

#ifndef NODE_H
#define NODE_H



class Node {
public:
    int data;
    Node *left = nullptr, *right = nullptr;
    int height = 0;
    Node (int data) {
        this->data = data;
    }
};



#endif //NODE_H
