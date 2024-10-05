//
// Created by Pranay Kamble on 02/10/24.
//
#include <iostream>
#include <queue>
#include <vector>

/*
//-----------------Naive Solution----------------------
std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>> &vectors, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pQueue; //Time Complexity: O((n*k) + (n*k*log(n*k))
                                                                          //Auxiliary Space: O((n*k))
    for (int i {}; i<k ; ++i) {                                           //n -> max vector length , k -> total vectors
        for (int j {}; j<vectors[i].size(); ++j) {
            pQueue.push(vectors[i][j]);
        }
    }

    std::vector<int> result;
    while (!pQueue.empty()) {
        result.push_back(pQueue.top());
        pQueue.pop();
    }

    return result;
}*/


//--------------------Efficient Approach-------------------
class Triplet {
public:
    int value, vPos, aPos;
    Triplet(int a, int b, int c) {
        this->value = a;
        this->vPos = b;
        this->aPos = c;
    }
};

class MyCMP {
public:
    bool operator() (const Triplet &a, const Triplet&b) const {
        return a.value > b.value;
    }
};

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>> &vectors, int k) {
    std::priority_queue<Triplet, std::vector<Triplet>, MyCMP> pQueue; //Time Complexity: O(k + (n*logk))
                                                                      //Auxiliary Space: O(k)
    for (int i {}; i<k; ++i) {
        pQueue.push(Triplet(vectors[i][0], i, 0));
    }

    std::vector<int> result;

    while (!pQueue.empty()) {
        result.push_back(pQueue.top().value);
        int vPos = pQueue.top().vPos;
        int aPos = pQueue.top().aPos;
        pQueue.pop();

        if (aPos + 1 < vectors[vPos].size()) {
            pQueue.push(Triplet(vectors[vPos][aPos+1], vPos, aPos+1));
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> vectors {{5,10},{4,9},{6}};
    int k = 3;

    std::vector<int> sorted = mergeKSortedArrays(vectors,k);

    for (int i: sorted) {
        std::cout << i << " ";
    }
    return 0;
}