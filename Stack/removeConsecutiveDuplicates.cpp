//
// Created by Pranay Kamble on 27/07/24.
//
#include <iostream>
#include <stack>

std::string removeConsecutiveDuplicates(std::string str) {
    std::string res;
    std::stack<char> temp;
    for (char i: str) {
        if (temp.empty() || temp.top() != i) {
            temp.push(i);
        }else {
            temp.pop();
        }
    }
    for ( ;!temp.empty(); temp.pop()) {
        res = temp.top() + res;
    }
    if (res == "") return "Empty String";
    return res;
}


int main() {
    std::string str {"aaaaaa"};
    std::cout << removeConsecutiveDuplicates(str) << std::endl;
    return 0;
}