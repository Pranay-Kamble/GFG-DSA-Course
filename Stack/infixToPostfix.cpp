//
// Created by Pranay Kamble on 01/08/24.
//
#include <iostream>
#include <string>
#include <stack>


int prec(char oper) {
    if (oper == '^')
        return 3;
    if (oper == '*' || oper == '/')
        return 2;
    if (oper == '+' || oper == '-')
        return 1;
    return -1;
}

std::string infixToPostfix(const std::string &infix) {
    std::string result;
    std::stack<char> stack;

    for (int i{}; i<infix.length(); ++i) {
        char letter  = infix[i];

        if (('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z') || ('0' <= letter && letter <= '9')) {
            result += letter;
        }else if (letter == '(') {
            stack.push(letter);
        }else if (letter == ')') {
            while (stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }else{
            while (!stack.empty() && (prec(letter) <= prec(stack.top()))) {
               result += stack.top();
               stack.pop();
            }
            stack.push(letter);
        }
    }

    while(!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    return result;
}


int main() {
    std::string infix = "a+b*(c^d-e)^(f+g*h)-i";
    std::cout << infixToPostfix(infix) << std::endl;
    return 0;
}