//
// Created by Pranay Kamble on 27/07/24.
//
#include <iostream>
#include <stack>

class KStack {
private:
    int *arr = nullptr;
    int *tops = nullptr; //array that stores the top index of kth stack
    int *links = nullptr;//array that stores the previous index of the element else stores the next freeSlot position
    int freeSlot {};
    int capacity {};
    int k {};
public:
    KStack(int n, int k) {
        this->capacity = n;
        this->k = k;
        this->arr = new int[n];
        this->tops = new int[k];
        this->links = new int[n];
        for (int i = 0; i < n; ++i) { //The top of not created stacks is -1;
            if (i<k)
                tops[i] = -1;
            links[i] = i+1;
            if (i == n-1)
                links[i] = -1;
        }
    }

    bool push(int data, int stackNo) {
        if (freeSlot == -1) return false; //Overflow
        if (stackNo >= this->k) return false; //There can only be k stacks
        int i {freeSlot};
        freeSlot = links[freeSlot];
        arr[i] = data; //just insert the data in arr
        links[i] = tops[stackNo]; //keep the previous top in parr
        tops[stackNo] = i; //Set new top for the specified stack
        return true;
    }

    int pop(int stackNo) {
        if (tops[stackNo] == -1) return -1;
        int i {tops[stackNo]};//store the top index
        tops[stackNo] = links[i]; //simulates pop, move top to previous top
        links[i] = freeSlot; //since the popped index is free now, we add link to the next freeSlot,So that it can jump to new place, after this slot is filled
        freeSlot = i; //then move the freeSlot to current popped
        return arr[i];
    }

    bool isEmpty(int stackNo) {
        if (stackNo >= this->k) return false;
        return tops[stackNo] == -1;
    }

    int top(int stackNo) {
        if (tops[stackNo] == -1) return -1;
        return arr[tops[stackNo]];
    }

    void print() {
        for (int j{}; j<capacity; ++j) {
            int i = arr[j];
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    KStack stack(10,3);
    // stack.pop(1);
    stack.push(10,2);
    stack.push(20,2);
    stack.push(30,1);
    stack.push(40,0);
    stack.push(50,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.push(60,2);
    stack.print();
    // stack.pop(2);
    stack.pop(1);
    // stack.pop(2);
    stack.print();
    std::cout << stack.top(1) << std::endl;
    std::cout << stack.top(2) << std::endl;
    std::cout << stack.top(2) << std::endl;
    std::cout << stack.top(2) << std::endl;
}