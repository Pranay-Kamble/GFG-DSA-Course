#include <iostream>

int hcf(const int &a, const int &b){        
    int x = a;
    int y = b;
    while (x!=y){
        (x > y ? x -=y : y-=x);
    }
    return x;
}

/*
--------------Mine and Sir's Solution----------------
int lcm(const int &a , const int &b){                           //Naive Solution :( 
    for (int large = (a>b ?a:b); large <= (a*b) ; ++large){     //Time Complexity = O(a * b)
        if(large%a == 0 && large%b == 0){
            return large;
        }
    }
    return (a*b);
}
-------------Efficient Approach bu sir, solved by own after knowing the fact--------------*/

int lcm(const int &a , const int &b){           // Using the fact -> (a*b) = gcd(a,b) * lcm(a,b)
    return ((a*b) / hcf(a,b));                  // => lcm(a,b) = (a*b) / gcd(a,b)  
}                                               

int main() {
    std::cout << lcm(3,7);
}