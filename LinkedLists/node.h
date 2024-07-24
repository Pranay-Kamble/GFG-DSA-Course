#ifndef NODE_H
#define NODE_H
#include "node.cpp"

Node::Node (int data, Node* next) {
    this->data = data;
    this->next = next;
}
#endif //NODE_H
