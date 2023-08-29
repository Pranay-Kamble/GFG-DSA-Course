#include <iostream>

void oneto_n(int n){
    if (n == 1){
        std::cout << n << " ";
        return;
    }
    oneto_n(n-1);
    std::cout << n << " ";
}

int main(){
    oneto_n(10);
    return 0;
}
