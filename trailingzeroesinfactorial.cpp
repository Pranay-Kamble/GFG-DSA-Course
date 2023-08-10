#include <iostream>

unsigned long long factorialof(const int &num){
    int copy {num};
    unsigned long long factorial {1};
    for (int i{1} ; i <= num ; ++i){
        factorial *= i;
    }
    return factorial;
}
/*
int trailingzeroes(const unsigned int &num){           My solution failed, as factorial of large numbers 
    unsigned long long factorial = factorialof(num);   could not be stored in even unsigned long long int
    int count {0};
    
    while(factorial % 10 == 0 ){
        ++count;
        factorial /= 10; 
    }
    return count;
}
*/
int trailingzeroes(const int &num){   //Formula to find the number of trailing zeroes =  no of times 5 present in primefactorisation of the number 
    int count {};
    for (int i{5} ; i <= num ; i*=5){  // Time complexity = Theta(log n)
        count += num/i;                // Auxiliary Space = Theta(1) , constant
    }
    return count;
}
int main (){
    std::cout << trailingzeroes(78);
}