#include <iostream>
#include <cmath>
/*
void divisorsof(const int &num){                        //Time Complexity = Theta(n) , Linear
    for (int i{1}; i <= (num/2); ++i){
        if(num % i == 0){
            std::cout << i << " ";
        }
    }
    std::cout << num ;
}
*/

void divisorsof(const int &num){    
    int i;                          //Time Complexity = Theta ( root(n) + root(n)) ==> Theta(root(n))
    for ( i = 1; i*i < num; ++i){       //Auxiliary Space = Theta(1)
        if(num%i == 0){
            std::cout << i << " ";
        }
    }
    for ( ; i!=0; --i){
        if(num%i == 0){
            std::cout << num/i << " ";
        }
    }
}

int main () {  
    divisorsof(100);
}