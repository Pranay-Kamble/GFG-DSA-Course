//
// Created by Pranay Kamble on 22/10/24.
//
#include <iostream>
#include <list>

struct Node {
    int data;
    Node *next = nullptr;
    Node(int data) {
        this->data = data;
    }
    Node() {
        data = 0;
    }
};

struct MyHash {
    int bucket;
    Node **table;

    MyHash(int size) {
        this->bucket = size;
        table = new Node*[bucket];
        for (int i = 0; i<size; ++i) {
            table[i] = nullptr;
        }
    }

    ~MyHash() {
        for (int i = 0; i<bucket; ++i) {
            delete table[i];
        }
        delete table;
    }

    int hashFunc(int value) {
        return (value%bucket);
    }

    void insert(int value) {
        int index = hashFunc(value); //search for the index

        if (table[index] == nullptr) {  //if the index is unoccupied then insert
            table[index] = new Node(value);
            return;
        }

        Node *temp = table[index];
        while (temp->next != nullptr && temp->data != value) //if index is occupied then check if the element exists
            temp = temp->next;                               //or go to the end of the chain

        if (temp->data == value) //if element is already present then no need to add
            return;

        temp->next = new Node(value);
    }

    bool search(int value) {
        int index = hashFunc(value);

        if (table[index] == nullptr) { //if there is no value at that index then return
            return false;
        }

        Node *temp = table[index];
        while (temp != nullptr && temp->data != value) //stop if reached end or found that value exists already
            temp = temp->next;

        if (temp == nullptr) //if reached end return false
            return false;

        return true; //else we have found the value and return true
    }

    void remove(int value) {
        int index = hashFunc(value);

        if (table[index] == nullptr) //if the index is empty then there is nothing to remove
            return;

        if (table[index]->data == value) //see if the first element in the index is the required node
            table[index] = table[index]->next;
        else {
            Node *temp = table[index]; // else move through the linked list chain and find the node to delete
            while (temp->next != nullptr && temp->next->data != value) {
                temp = temp->next;
            }

            if (temp->next == nullptr)
                return;

            temp->next = temp->next->next;
        }
    }
};


int main() {
    MyHash map(5);
    map.insert(70);
    map.insert(71);
    map.insert(9);
    map.insert(56);
    map.insert(72);

    printf("%d - %d\n", map.search(56), map.search(57));
    map.insert(57);
    map.remove(56);
    map.remove(57);
    printf("%d - %d\n", map.search(56), map.search(57));
    return 0;
}