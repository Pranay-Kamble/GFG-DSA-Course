//
// Created by Pranay Kamble on 16/07/24.
//
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};

Node* insertAtEnd(Node* head, int data) {
    Node* addNode = new Node(data);
    if (head == nullptr) return addNode;

    Node* curr = head;
    while(curr->next != nullptr)
        curr = curr->next;
    curr->next = addNode;
    return head;
}

Node* insertAtBegin(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

//------------Naive Approach-----------(Using temporary array)
/*Node* reverse(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }

    std::vector<int> aux {};
    for (Node* temp = head; temp!= nullptr; temp = temp->next) {
        aux.push_back(temp->data);
    }
    Node* curr = head;
    for (; aux.size()!=0 ;) {     //aux.size() decreases after every pop
        curr->data = aux.back();
        curr = curr->next;
        aux.pop_back();
    }
    return head;
}*/


//-----------Efficient Approach------------(not inplace)
/*Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* newHead = nullptr;
    Node* deleteNode = head;
    while (head != nullptr) {
        newHead = insertAtBegin(newHead,head->data);
        deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    return newHead;
}*/

//--------Best Solution-----------(inplace)
Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* prev {nullptr}; //before head
    Node* curr {head};
    Node* next {curr->next}; //after head
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printLinkedList(Node* head) {
    if (head == nullptr) {
        std::cout << nullptr << std::endl;
        return;
    }
    while(head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,0);
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    head = insertAtEnd(head,40);
    head = insertAtEnd(head,50);
    printLinkedList(head);
    head = reverse(head);
    printLinkedList(head);
    return 0;
}