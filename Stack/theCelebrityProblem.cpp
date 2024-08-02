//
// Created by Pranay Kamble on 01/08/24.
//
#include <iostream>

const int rows = 5, columns = 5;

int findCelebrity(int mat[rows][columns], int size) {
    int arr[rows] {};
    int celebrity = -1;
    for (int i{}; i<rows; ++i) {
        bool flag = true;
        for (int j{}; j<rows; ++j) {
            arr[j] += mat[i][j];
            if (mat[i][j] == 1)
                flag = false;
        }
        if (flag and celebrity == -1)
            celebrity = i;
        else if (flag)
            return -1;
    }
    return arr[celebrity] == rows-2? celebrity:-1;;
}

int main() {
    int mat[rows][columns] = {{0,0,0,1,0}, {1,0,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,1,0}};
    std::cout << "Celebrity: " << findCelebrity(mat,rows) << std::endl;

    return 0;
}