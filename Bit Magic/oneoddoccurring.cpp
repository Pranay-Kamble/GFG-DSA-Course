#include <iostream>

/*
Properties of XOR (^) Operator
 -It returns true if both the values are different.
 -It is commutative ==> (x^y)^z == x^(y^z)
 - x^x = 0
 - x^0 = x 
*/
int findoneodd(int arr[], int size){        //Time Complexity = Theta(size of array)
    int result {arr[0]};
    for (int i{1}; i < size ; ++i){
        result = (result ^ arr[i]);
    }
    return result;
}

int main() {
    int arr [] {1,1,1,1,2,2,2,3,3,6,6,6,6};
    std::cout << findoneodd(arr,13);
}