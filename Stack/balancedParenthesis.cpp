//
// Created by Pranay Kamble on 27/07/24.
//

#include <iostream>
#include <stack>


bool isMatching(char a, char b) {
    return ((a=='(' && b==')') || (a=='[' && b ==']') || (a=='{' && b=='}'));
}

bool balancedParentheses(const std::string &str) { //Time Complexity = O(n), Space Complexity = O(n)
    if (str.length() %2 == 1) return false; // if balanced, then there will be even characters.

    std::stack<char> store;
    for (char i : str) {
        if (i == '(' || i == '[' || i == '{') //if it is open bracket, then push in the stack
            store.push(i);
        else if (store.empty()) //if there are closing brackets without opening bracket
            return false;
        else if (isMatching(store.top(),i)) //if top bracket is closed, then pop it
            store.pop();
        else
            return false;
    }
    return store.empty();
}

int main() {
    std::string str {"{}}}"};
    std::cout << std::boolalpha << balancedParentheses(str) << std::endl;
    return 0;
}