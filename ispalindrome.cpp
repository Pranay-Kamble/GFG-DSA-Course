#include <iostream>
#include <string>
#include <algorithm>
/*
 --------------My Approach------------------
bool ispalindrome(const int &num){
    std::string nums  = std::to_string(num) ;
    std::string reverse {};
    for (int i = nums.size()-1; i >= 0 ; --i) {
        reverse.push_back(nums.at(i));
    }   
    return(nums == reverse);
} 
*/

//--------Sir's Approach------------
bool ispalindrome (const int &num){
    int copy = num;
    int reverse {};
    int last_digit{};
    while (copy != 0) { //Take last digit by modulo, add this last digit to reverse 
                        //by multiplying by 10 (to create a new digit) and adding it to reverse ,
                        // then remove the last digit by division by 10 on original number 
        last_digit = copy % 10;
        reverse = (reverse * 10) + last_digit;
        copy /= 10;
    }
    return (num == reverse);
}

int main(){
    std::cout << std::endl;
    std::cout << std::boolalpha << ispalindrome(12321);
}