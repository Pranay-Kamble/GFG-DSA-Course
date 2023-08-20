#include <iostream>
#include <cmath>
/*
//Naive Approach -> Iterate from i = 2 to i = n-1 and check if each i divides n or not, if divides then not prime
bool isprime(const int &num)
{
    if(num == 1 || num == 0) {
        return false;
    }
    for (int i{2}; i < num ; ++i){
        if (num % i == 0){
            return false;
        }
    }
    return true; 
}

// Efficient Approach -> Iterate from i = 2 to just i = root(n), and check if i divides n or not
// Proof,--------------------
//  All divisors of a number appear in a pair,
//  Example ---> 24 ===> (1,24) , (2,12), (3,8) , (8,3) , (12,2) , (24,1).
// let( x,y ) be a pair of divisors
// let x<=y , since x and y are divisors , x*y = n
// x <= y ===> x*x <= n ===> x <= root(n) 
//-------------------------------
------------My Solution and sir's solution using efficient approach---------------*/
bool isprime(const int &num){
    if (num == 1)
        return false;
    int root = sqrt(num);
    for(int i{2}; i <= root ; ++i){
        if (num % i == 0)
            return false;
    }
    return true;
}
int main()
{
    std::cout << std::boolalpha << isprime(3);
    return 0;
}