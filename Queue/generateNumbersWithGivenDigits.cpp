//
// Created by Pranay Kamble on 06/08/24.
//
#include <iostream>
#include <queue>

void generateNnumbers(int n) {
    std::queue<std::string> queue;
    queue.push("5");
    queue.push("6");
    for (int i{}; i<n; ++i) {
        std::string curr {queue.front()};
        queue.pop();
        std::cout << curr << " ";
        queue.push(curr + "5");
        queue.push(curr + "6");
    }
    std::cout << std::endl;
}


int main() {
    generateNnumbers(10);
    return 0;
}