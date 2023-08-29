#include <iostream>
/*
------------Sir's Solution---------
int sumtilln(int n){                //Time Complexity = Theta(n) , Auxiliary Space = Theta(n)
    if (n == 0){
        return 0;
    }
    return (n+(sumtilln(n-1)));     //Non-Tail Recursive Function
}

------------My Solution------------*/
int sumtilln(int n , int sum = 0){     //Time Complexity = Theta(n) , Auxiliary Space = Theta(n)
    if(n <= 0){
        return (sum);
    }
    return sumtilln(n-1,sum+n);     //Tail Recursive Function -> More Faster
}

int main(){
    std::cout << "Sum of first 12 natural numbers is "<< sumtilln(12);
    return 0;
}