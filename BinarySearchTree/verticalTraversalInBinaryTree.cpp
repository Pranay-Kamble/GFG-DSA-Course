//
// Created by Pranay Kamble on 20/09/24.
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

//------------------Approach -1------------------------
// void verticalHelper(Node *root, std::map<int, std::map<int,int>> &map, int hDist = 0) {
//     if (root == nullptr)
//         return;
//
//     verticalHelper(root->left, map, hDist-1);
//     map[hDist][root->data];
//     verticalHelper(root->right, map, hDist+1);
// }
//
// void verticalTraversal(Node *root) { //Time Complexity: Theta(n logn + width*width) ~ Theta(n logn)
//     std::map<int , std::map<int,int>> map;
//     verticalHelper(root, map);
//
//     for (std::pair<int, std::map<int,int>> i: map ) {
//         for (std::pair<int, int> j: i.second) {
//             std::cout << j.first << " ";
//         }
//     }
// }


//----------------Approach-2 --------------------------
void levelOrder(Node *root, std::map<int, std::vector<int>> &map) {
    if (root == nullptr)
        return;

    std::queue<std::pair<Node *, int>> queue;
    queue.push({root, 0});
    while (!queue.empty()) {
        std::pair<Node *, int> top = queue.front();
        queue.pop();

        Node *front = top.first;
        int hDist = top.second;

        map[hDist].push_back(front->data);

        if (front->left != nullptr)
            queue.push({front->left, hDist-1});
        if (front->right != nullptr)
            queue.push({front->right, hDist+1});
    }
}

void verticalTraversal(Node *root) {  //Time Complexity: O(n + width*height) ~ O(n)
    std::map<int, std::vector<int>> map;
    levelOrder(root, map);

    for (std::pair<int, std::vector<int>> i: map) {
        for (int j: i.second) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

    std::cout << std::endl;
}

Node* insertInBST(Node *root, int data) {
    if (root == nullptr)
        return new Node(data);

    if (root->data == data)
        return root;

    if (root->data > data)
        root->left = insertInBST(root->left, data);
    else
        root->right = insertInBST(root->right, data);

    return root;
}

void free(Node *root) {
    if (root == nullptr)
        return;

    free(root->left);
    free(root->right);
    delete root;
}

int main() {
    Node *root = nullptr;
    //
    // root = insertInBST(root, 10);
    // root = insertInBST(root, 20);
    // root = insertInBST(root, 30);
    // root = insertInBST(root, 40);
    // root = insertInBST(root, 50);

    root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    verticalTraversal(root);

    free(root);
    return 0;
}