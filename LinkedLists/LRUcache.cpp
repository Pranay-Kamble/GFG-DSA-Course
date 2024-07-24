//
// Created by Pranay Kamble on 22/07/24.
//
#include <iostream>
#include <unordered_map>

struct Node {  //Doubly Linked List Node
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node (int data) {
        this->data = data;
    }
};

class LRUCache {
    int fixedSize {};
    int size {};
    Node* head = nullptr;
    Node* tail = nullptr;
    std::unordered_map<int,Node*> storage {};
public:

    LRUCache(const int size) {
        fixedSize = size;
    }

    void printCache() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << "<->";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void set(int key,int data) {
        std::unordered_map<int,Node*>::iterator find = storage.find(key);
        if (find == storage.end()) {  //element is not present, then add node at start
            Node* newNode = new Node(data);
            newNode->next = head;

            if (tail == nullptr)
                tail = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;

            if (size >= fixedSize) { //deletes the Least Recently Used
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
                size--;
            }
            storage.insert({key,newNode});
            ++size;
        } else { //if element is present, then update the value of the key
            Node* node = find->second;
            node->data = data;
            this->get(key);
        }
        printCache();
    }

    int get(int key) {
        std::unordered_map<int,Node*>::iterator find {this->storage.find(key)};
        if (find == this->storage.end()) //element not present, then return -1
            return -1;

        //if element is present, then move it to Most Recently Used(start position) and return data of it
        Node* node = find->second;
        if (node == head)  //if required node is already at head, then no need to move it, we can just return
            return head->data;
        if (node == tail) //we move tail to prev, cause below code will then shift the node to start
            tail = tail->prev;
        if (node->next != nullptr) //false if node is at tail
            node->next->prev = node->prev;

        node->prev->next = node->next;
        node->prev = nullptr;
        node->next = head;
        head = node;
        return node->data;
    }
};