//
// Created by Pranay Kamble on 24/07/24.
//
#include <iostream>

struct Node {
    char data;
    Node* next = nullptr;
    Node (int data) {
        this->data = data;
    }
};


void deleteLinkedList(Node* head) {
    Node* prev = head;
    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }
}

/*bool isPalindrome(Node* head) { //Time Complexity = O(n), Space Complexity = O(n)
    if (head == nullptr) return false;
    if (head->next == nullptr) return true;

    Node* curr = head;
    Node* newList = nullptr;
    Node* newNode = nullptr;
    while (curr != nullptr) {
       newNode = new Node(curr->data);
        if (newList == nullptr)
            newList = newNode;
        else {
            newNode->next = newList;
            newList = newNode;
        }
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr && newList != nullptr) {
        if (curr->data != newList->data) {
            deleteLinkedList(newList);
            return false;
        }
        curr = curr->next;
        newList = newList->next;
    }
    deleteLinkedList(newList);
    return true;
}*/

Node* reverseLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node *prev=nullptr, *curr = head, *next = head->next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    //Idea: Find middle and reverse the list after it, then keep comparing element from start and mid+1 simultaneously
    //For even nodes, take the first middle.
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) { //extra third condition to find the first middle in even nodes
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseLinkedList(slow->next);
    fast = slow->next;
    slow = head;
    while (slow != nullptr && fast != nullptr) {
        if (slow->data != fast->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}


Node* insertAtEnd(Node* head, int data) {
    Node* node = new Node(data);
    if (head == nullptr) return node;

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = node;
    return head;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head,'g');
    head = insertAtEnd(head,'e');
    head = insertAtEnd(head,'e');
    head = insertAtEnd(head,'f');
    std::cout << std::boolalpha << isPalindrome(head) << std::endl;
    deleteLinkedList(head);
    return 0;
}
