//
// Created by Pranay Kamble on 14/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

int searchIteratively(Node* head, int search) {
    int position {1};
    while (head != nullptr) {
        if (head->data == search)
            return position;
        ++position;
        head = head->next;
    }
    return -1;
}

int searchRecursively(Node* head, int search, int position = 1) {
    if (head == nullptr) {
        return -1;
    }
    if (head->data == search) {
        return position;
    }
    return searchRecursively(head->next,search,++position);
}

void printLinkedList(Node* head) { //head variable is copied and is not same as the one in main()
    Node* traverse = head;
    while(traverse != nullptr) {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printLinkedList(head);
    std::cout << std::endl;
    std::cout << "The position of element is " << searchRecursively(head,40) << "\n";
    return 0;
}