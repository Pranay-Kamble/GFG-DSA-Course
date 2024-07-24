//
// Created by Pranay Kamble on 18/07/24.
//
#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
Node* insertAtEnd(Node* head, int data) {
    Node *newNode = new Node(data);
    if (head == nullptr)
        return newNode;
    Node* last = head;
    while (last->next != nullptr)
        last = last->next;
    last->next = newNode;
    return head;
}
//
// Node* segregateEvenAndOddNodes(Node* head) {
//     if (head == nullptr || head->next == nullptr)
//         return head;
//     Node* ptr = head;
//     Node* nextInsert = nullptr;
//     bool isInserted = false;
//
//     if (head->data %2 == 0) {
//         nextInsert = head;
//         isInserted = true;
//     }
//     while (ptr->next != nullptr) {
//
//         if (ptr->next->data%2 == 0) { //If next node is even, then insert it at beginning
//             Node* temp = ptr->next->next;
//             if (!isInserted) {
//                 ptr->next->next = head;
//                 nextInsert = head;
//                 isInserted = true;
//             }
//             else {
//                 ptr->next->next = nextInsert->next;
//                 nextInsert->next = ptr->next;
//                 nextInsert = nextInsert->next;
//             }
//             ptr->next = temp;
//
//         }else {
//             ptr = ptr->next;
//         }
//     }
//     return head;
// }

Node* segregateEvenAndOddNodes(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *os = nullptr,*es = nullptr,*oe = nullptr,*ee = nullptr;

    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data %2 ==0) {

            if (es == nullptr && ee == nullptr) {
                es = ee = curr;
            }else {
                ee->next = curr;
                ee = ee->next;
            }

        }else {

            if (os == nullptr && oe == nullptr) {
                os = oe = curr;
            }else {
                oe->next = curr;
                oe = oe->next;
            }
        }
        curr = curr->next;
    }
    if (os == nullptr || es == nullptr) {
        return head;
    }
    oe->next = nullptr;
    ee->next = os;
    return es;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,8);
    head = insertAtEnd(head,12);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);
    head = insertAtEnd(head,6);
    head = insertAtEnd(head,7);
    head = insertAtEnd(head,8);
    head = insertAtEnd(head,9);
    printLinkedList(head);
    head = segregateEvenAndOddNodes(head);
    printLinkedList(head);

    return 0;
}