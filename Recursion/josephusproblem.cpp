#include <iostream>
#include <vector>

unsigned int josephus(int n ,const int &k){
    if (n == 1){
        return 0;
    }
    return (josephus(n-1,k)+ k)%n;  //Modulo a%b --> result will always be within range 0<= x%y < y
}

int main(){
    std::cout << josephus(10000,10);
}