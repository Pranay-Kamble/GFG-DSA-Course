//
// Created by Pranay Kamble on 09/08/24.
//
#include <iostream>
#include <deque>

/*
//---------------Naive Solution-----------------
int firstCircularTour(int dist[], int pet[], int size) { //Time Complexity: O(n^2), Auxiliary Space: O(1)
    for (int i{}; i<size; ++i) {
        int currPetrol {pet[i] - dist[i]};
        int temp {(i+1)%size};
        while (currPetrol >= 0 && temp != i) {
            currPetrol += (pet[temp] - dist[temp]);
            temp = (temp+1)%size;
        }
        if (currPetrol >= 0) return (i+1);
    }
    return -1;
}
*/

int firstCircularTour(int dist[], int pet[], int size) {
    //keep adding items to the end of deque while currpetrol is greater than or equal to zero
    //keep removing items from the front of deque while currpetrol is negative
    std::deque<int> deque;

    for (int i{}; i<size; ++i) {
        int currPetrol = 0;
        int ptr = i+1;
        currPetrol += pet[i];
        deque.push_back(i);
        while (currPetrol >= 0 && ptr != i) {
            currPetrol += (pet[ptr] - dist[ptr]);
            deque.push_back(ptr);
            ptr = (ptr+1)%size;
        }
        if (ptr == i && currPetrol >= 0)
            return i;

        while (currPetrol <= 0) {
            currPetrol -= pet[deque.front()];
            deque.pop_front();
        }

        if (currPetrol >= 0)
    }
}


int main() {
    int petrol[] {50,10,60,100};
    int dist[] {30,20,100,10};
    const int size {std::size(petrol)};
    std::cout << "First Circular Tour is possible at petrol pump no: " << firstCircularTour(dist,petrol,size);
    return 0;
}