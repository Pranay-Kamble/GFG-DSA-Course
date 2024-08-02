//
// Created by Pranay Kamble on 26/07/24.
//

#include <iostream>
#include <stack>
/*
//---------By using extra stack----------
void deleteMid(std::stack<int> &stack, int sizeOfStack) { //Time Complexity = O(n), Space Complexity = O(n)
    std::stack<int> temp;
    for (int i {}; i<(sizeOfStack/2); ++i) {
        temp.push(stack.top());
        stack.pop();
    }
    stack.pop();
    while (temp.empty() == false) {
        stack.push(temp.top());
        temp.pop();
    }
}
*/

//----------By using recursion-----------
void deleteMid(std::stack<int> &stack, int sizeOfStack, int call = 0) {
    int top = stack.top();
    stack.pop();
    if (call == sizeOfStack/2)
        return;
    deleteMid(stack,sizeOfStack,++call);
    stack.push(top);
}

int main() {
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    deleteMid(stack,stack.size());
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
    return 0;
}