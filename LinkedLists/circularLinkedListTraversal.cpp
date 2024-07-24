//
// Created by Pranay Kamble on 15/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next {nullptr};
    Node (int data) {
        this->data = data;
    }
};

void printLinkedList(Node* head) {
    if (head == nullptr)
        return;

//Method-1
    Node* curr {head};
     do{
        std::cout << curr->data << " ";
        curr = curr->next;
    }while (curr != head);
    std::cout << std::endl;
//Method-2 - Using the for loop
    /*std::cout << head->data << " ";
    for (Node* curr = head->next; curr!=head; curr = curr->next){
        std::cout << curr->data << " ";
    }
    std::cout<< std::endl;*/

}

int main() {
    Node* head {new Node(0)};
    head->next = {new Node(10)};
    head->next->next = new Node(20);
    head->next->next->next = head;
    printLinkedList(head);

    return 0;
}