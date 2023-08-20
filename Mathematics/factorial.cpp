#include <iostream>
/*
--------------My Iterative Solution-------------------
unsigned long long factorialof(const int &num){    //Time Complexity = O(n) , Linear
    unsigned long long factorial {1};              //Auxiliary Space = O(n) , copy variable is dependent on num
    int copy = num;
    while (copy > 0){
        factorial *= copy;
        --copy;  
    }
    return factorial;
}

--------------My Recursive Solution , same as Sir's Recursive Solution-------------------
unsigned long long factorialof(const int &num){             //Recurrence Relation=> T(n) = T(n-1) + Theta(1) 
    if(num <= 0)                                            //Time Complexity = O(n)
        return 1;                                                                       
    return num * (factorialof(num - 1));
}

-------------Sir's Solution--------------------------*/
unsigned long long int factorialof(const int &num){         //Time Complexity = Theta(n) , Linear
    unsigned long long int factorial {1};                   //Auxiliary Space = Theta (1) , Constant
    for (int i {1} ; i <= num ; ++i){
        factorial *= i;
    }
    return factorial;
}

int main(){
    std::cout << factorialof(0);
    return 0;
}