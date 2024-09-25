//
// Created by Pranay Kamble on 22/09/24.
//
#include <iostream>
#include <map>
#include <queue>

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;

    Node (int data) {
        this->data = data;
    }
};


/*
//---------------------Naive Approach--------------------
void topViewHelper(Node *root, std::map<int, std::vector<int>> &map) {
    if (root == nullptr)
        return ;

    std::queue<std::pair<Node *, int>> queue;
    queue.push({root,0});

    while (!queue.empty()) {
        Node *front = queue.front().first;
        int hDist = queue.front().second;

        queue.pop();
        map[hDist].push_back(front->data);
        if (front->left != nullptr)
            queue.push({front->left, hDist-1});
        if (front->right != nullptr)
            queue.push({front->right, hDist+1});
    }
}

void topViewOfBinaryTree(Node *root) { //Time Complexity: O(n*logn), Auxiliary Space: O(width)
    std::map<int , std::vector<int>> map;
    topViewHelper(root, map);

    for (std::pair<int, std::vector<int>> i: map) { //Just print the first element of the vector
        std::cout << i.second[0] << " ";
    }
    std::cout << std::endl;
}
*/

//---------------------Efficient Approach-----------------------
void topViewHelper(Node *root, std::map<int, int> &map) {
    if (root == nullptr)
        return;

    std::queue<std::pair<Node*, int>> queue;
    queue.push({root,0});

    while (!queue.empty()) {
        Node *front = queue.front().first;
        int hDist = queue.front().second;

        queue.pop();

        if (map.find(hDist) == map.end()) {  //Only store the first element on the vertical
            map[hDist] = front->data;
        }

        if (front->left != nullptr)
            queue.push({front->left, hDist-1});
        if (front->right != nullptr)
            queue.push({front->right, hDist+1});
    }
}

void topViewOfBinaryTree(Node *root) {  //Time Complexity: O(N), Auxiliary Space: O(n)
    std::map<int, int> map;
    topViewHelper(root, map);

    for (std::pair<int,int> i: map) {
        std::cout << i.second << " ";
    }
    std::cout << std::endl;
}

void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = new Node (10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right = new Node(50);
    root->right->left = new Node(60);
    // root->right->right = new Node(70);

    topViewOfBinaryTree(root);

    free(root);
    return 0;
}