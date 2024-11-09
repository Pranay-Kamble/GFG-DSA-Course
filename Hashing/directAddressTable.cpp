//
// Created by Pranay Kamble on 05/10/24.
//
#include <iostream>

bool arr[1000];

void initialise();
bool search(int key);
void insert(int key);
void remove(int key);

int main() {
    for (int i {}; i<244; ++i) {
        insert(i%32 + 4);
    }

    for (int i {}; i<100; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

void initialise() {
    for (int i {}; i<1000; ++i) {
        arr[i] = false;
    }
}

bool search(int key) {
    return arr[key];
}

void insert(int key) {
    arr[key] = true;
}

void remove(int key) {
    arr[key] = false;
}