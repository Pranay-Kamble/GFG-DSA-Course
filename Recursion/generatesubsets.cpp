#include <iostream>
#include <string>

void subsetsof(const std::string &word, std::string current = "", int index = 0){
    if (index == word.length()){
        std::cout << current<<" ";
        return;
    }
    subsetsof(word , current , index+1);
    subsetsof(word, current+ word.at(index),index+1);    
}

int main(){
    subsetsof("ABC");
    return 0;
}