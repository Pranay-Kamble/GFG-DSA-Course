#include <iostream>
/*
---------------My Solution----------------------------
int gcd(const int& a, const int& b){            //Time Complexity = O(smaller of a and b) , Linear
    int small = (a > b? b:a);                   
    for (;small != 0 ; --small){
        if (b % small == 0 && a % small == 0){
            return small;
        }
    }
    return 1;
}

------------Sir's Iterative Solution-----------------------
int gcd(const int &a, const int &b){       //Using the Euclidian Algorithm to find GCD
    int tempa = a;                         
    int tempb = b;
    while (tempa != tempb){
        (tempa>tempb ? (tempa -= tempb) : (tempb -= tempa));
    }
    return tempa;
}
-------------Sir's Recursive Solution--------------------*/
int gcd(const int &a , const int &b){
    if (b == 0)
        return a;
    return gcd(b , a%b);
}

int main() {
    std::cout << gcd(123135,1526885);
}