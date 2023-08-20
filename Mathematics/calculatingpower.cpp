#include <iostream>
/*
unsigned long long int pow(const int &a, const int &b){     //Time Complexity = O(b)
    unsigned long long int result {1};
    for (int i{}; i < b; ++i){
        result *= a;
    }
    return result;
}*/

unsigned long long int pow(const int &a ,const int &b){
    unsigned long long int result {1};

    for (int i{} ; i<b/2 ; ++i){
        result *= a;
    }
    if(b%2 == 0){
        return result*result;
    }
    for(int i{b/2+1}; i<=a ; ++i){
        result *= a;
    }
    return result;
}
int main() {
    std::cout << pow(3,3);
    return 0;
}