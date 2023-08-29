#include <iostream>
#include <string>
/*
-----------My Solution----------------*/
bool ispalindrome(std::string word){
    if((word.length() == 0) || (word.length() == 1)){
        return true;
    }
    if (word.front() == word.back()){
        word.erase(word.begin());
        word.pop_back();
        return ispalindrome(word);
    }  
    return false;
}

int main(){
    std::cout << std::boolalpha << ispalindrome("abbcbba") ;
    return 0;
}