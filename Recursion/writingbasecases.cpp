#include <iostream>

int factorialof(int n){
    if (n==0){              //Base Case, factorial of zero is 1
        return 1;
    }
    return n*factorialof(n-1);
}
int nthfibonacci(const int &n){
    if (n==0 || n==1){          //Base Case, for 0 and 1st fibonacci number
        return n;
    }
    return (nthfibonacci(n-1) + nthfibonacci(n-2));
}

int main(){
    std::cout << "The factorial of 10 is " << factorialof(10)<< "\n";
    std::cout << "The 12th fibonacci number is "<< nthfibonacci(12);
    return 0;
}