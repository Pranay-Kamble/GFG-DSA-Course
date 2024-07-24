//
// Created by Pranay Kamble on 18/07/24.
//
#include <iostream>
#include <unordered_set>
struct Node {
    int data;
    Node* next= nullptr;
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

Node* insertAtEnd(Node* head,int data) {
    Node* newNode = new Node(data);
    if (head == nullptr)
        return newNode;

    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    tail->next = newNode;
    return head;
}

int length(Node* head) {
    int length {};
    while (head != nullptr) {
        ++length;
        head = head->next;
    }
    return length;
}

/*int intersectionNode(Node* head1, Node* head2) { //Time Complexity = O(m+n), Space Complexity = O(m)
    if (head1 == head2)
        return head1->data;

    std::unordered_set<int> collection {};
    while (head1 != nullptr) {
        collection.insert(head1->data);
        head1 = head1->next;
    }

    while(head2 != nullptr) {
        if (collection.find(head2->data) != collection.end())
            return head2->data;
        head2 = head2->next;
    }
    return -1; //No Intersection
}
*/

int intersectionNode(Node* head1, Node* head2) {
    int count1 {length(head1)},count2 {length(head2)};
    Node *larger {count1 > count2? head1: head2}, *smaller{larger == head1? head2:head1};

    for (int i {}; i< abs(count1-count2); ++i) {
        larger = larger->next;
    }

    while (larger!=nullptr && smaller!=nullptr) {
        if (larger == smaller)
            return larger->data;
        larger = larger->next;
        smaller = smaller->next;
    }
    return -1;
}


int main() {
    Node *head1 = nullptr, *head2 = nullptr;
    head1 = insertAtEnd(head1,10);
    head1 = insertAtEnd(head1,20);
    head1 = insertAtEnd(head1,30);
    head2 = head1->next->next;
    head1 = insertAtEnd(head1,40);
    head1 = insertAtEnd(head1,50);
    head1 = insertAtEnd(head1,60);
    printLinkedList(head1);
    printLinkedList(head2);
    std::cout << "Intersection Node: " << intersectionNode(head1,head2) << std::endl;

    return 0;
}