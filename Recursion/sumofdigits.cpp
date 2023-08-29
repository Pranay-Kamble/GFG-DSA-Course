#include <iostream>
/*
---------Sir's Solution---------------
int sumofdigitsof(int num){
    if (num <= 9){          //Time Complexity = O(n) , Auxiliary Space = O(n)
        return num;
    }
    return (num%10 + sumofdigitsof(num/10)); //Non Tail Recursive
}
---------My Solution---------------*/
int sumofdigitsof(int num, int result = 0){
    if(num <= 9){               //Time Complexity = O(n) , Auxiliary Space = O(n)
        return (result+num);
    }
    return sumofdigitsof(num/10,result+=num%10); //Tail Recursive
}

int main(){
    std::cout << sumofdigitsof(99998);
    return 0;
}