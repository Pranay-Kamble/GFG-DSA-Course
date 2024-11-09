//
// Created by Pranay Kamble on 24/10/24.
//
#include <iostream>

class MyHash {
private:
    int *arr;
    int bucket;
    int size;

    int hashKey(int value) {
        return value%bucket;
    }

public:
    MyHash(int size) {
        arr = new int[size];
        this->bucket = size;
        this->size = 0;
        for (int i = 0; i<size; ++i)
            arr[i] = -1;
    }

    ~MyHash() {
        delete arr;
    }

    void print() {
        for (int i = 0; i<bucket; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    bool search(int value) {
        int hash = hashKey(value);
        int i = hash;
        while (arr[i] != -1) {
            if (arr[i] == value)
                return true;
            i = (i+1)%bucket;  // (a+b)%m = ((a%m) + (b%m)) %m
            if (i == hash) //we have searched for all the positions and reached the same place
                return false;
        }
        return false;
    }

    bool insert(int value) {
        if (size == bucket)
            return false;

        int hash = hashKey(value);
        int i = hash;

        while (arr[i] != -1 && arr[i] != -2) {
            if (arr[i] == value) //duplicate value
                return false;
            i = (i+1)%bucket;
            //No need to check if we reached the same point, as it is checked in size == bucket condition
        }
        arr[i] = value;
        ++this->size;
        return true;
    }

    bool remove(int value) {
        if (size == 0)
            return false;

        int hash = hashKey(value);
        int i = hash;
        while (arr[i] != -1) {  //loop till we find the first empty slot
            if (arr[i] == value) {
                arr[i] = -2;
                --this->size;
                return true;
            }

            i = (i+1) % size;
            if (i == hash)
                return false;
        }
        return false;
    }

};

int main() {
    MyHash map(7);
    map.print();
    map.insert(49);
    map.insert(50);
    map.insert(63);
    map.insert(64);
    map.insert(69);
    map.insert(68);
    map.print();
    map.remove(10);
    map.remove(50);
    map.remove(69);
    // map.insert(23);
    map.print();

    return 0;
}