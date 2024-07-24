//
// Created by Pranay Kamble on 12/07/24.
//
#include <iostream>
#include "node.h"

int main() {
    Node* linkedList = new Node(10);
    linkedList->next = new Node(20);
    linkedList->next->next = new Node(30);
    std::cout << linkedList->next->next->data;

}