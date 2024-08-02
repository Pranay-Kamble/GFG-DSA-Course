//
// Created by Pranay Kamble on 02/08/24.
//
#include <iostream>
#include <stack>


int pref(char letter) {
    if (letter == '^')
        return 3;
    if (letter == '+' || letter == '-')
        return 1;
    if (letter == '*' || letter == '/')
        return 2;
    return 0;
}


std::string infixToPrefix(std::string infix) {
    std::string result;
    std::stack<char> stack;

    for (auto i{infix.length()-1}; (int)i >= 0; --i) {
        char letter = infix[i];
        if (('a' <= letter && letter >= 'z') || ('A' <= letter && letter >= 'Z') || ('0' <= letter && letter >= '9')) {
            result += letter;
        }else {
            if (stack.empty())
                stack.push(letter);
            else if (letter == ')')
                stack.push(letter);
            else if (letter == '(') {
                while (stack.top() != ')') {
                    result += stack.top();
                    stack.pop();
                }
                stack.pop();
            }
            else if (pref(stack.top()) > pref(letter)) {
                while (pref(stack.top()) > pref(letter)) {
                    result += stack.top();
                    stack.pop();
                }
                stack.push(letter);
            }
            else if (pref(stack.top()) < pref(letter)){
                stack.push(letter);
            }
            else { //same precedence
                if (infix[i] == '^') {
                    while (pref(stack.top() > pref(letter))) {
                        result += stack.top();
                        stack.pop();
                    }
                }
                stack.push(letter);
            }
        }
    }

    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string infix = "x+y*z/w+u";
    std::cout << "The prefix expression is " << infixToPrefix(infix) << std::endl;
    return 0;
}