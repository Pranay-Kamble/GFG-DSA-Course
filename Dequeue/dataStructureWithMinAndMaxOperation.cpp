//
// Created by Pranay Kamble on 08/08/24.
//
#include <iostream>
#include <deque>

struct MyDS { //MyDS-> MyDataStructure
    std::deque<int> deque;

    void insertMin(int data) {
        if (deque.empty() || deque.front() > data) {
            deque.push_front(data);
        }
    }

    void insertMax(int data) {
        if (deque.empty() || deque.back() < data) {
            deque.push_back(data);
        }
    }

    int getMin() {
        if (deque.empty()) return INT_MAX;

        return deque.front();
    }

    int getMax() {
        if (deque.empty()) return INT_MIN;

        return deque.back();
    }

    int extractMin() {
        if (deque.empty()) return INT_MAX;

        int a = deque.front();
        deque.pop_front();
        return a;
    }

    int extractMax() {
        if (deque.empty()) return INT_MIN;

        int a = deque.back();
        deque.pop_back();
        return a;
    }
};

int main() {
    MyDS deque;
    deque.insertMin(5);
    deque.insertMax(10);
    deque.insertMin(3);
    deque.insertMax(15);
    deque.insertMin(2);
    std::cout << deque.getMin() << "\n" << deque.getMax() << std::endl;
    deque.insertMin(1);
    std::cout << deque.getMin() << std::endl;
    deque.insertMax(20);
    std::cout << deque.getMax();
    return 0;
}