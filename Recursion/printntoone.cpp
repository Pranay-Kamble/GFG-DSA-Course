#include <iostream>

void ntoone(int n){
    if(n == 0){
        return;
    }
    std::cout << n << " ";
    ntoone(n-1);
}

int main(){
    ntoone(10);
    return 0;
}