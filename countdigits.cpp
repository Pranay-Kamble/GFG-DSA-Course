#include <iostream>
#include <sstream>
using namespace std;

int countdigits(const int &num){
    std::stringstream ss;
    ss << num;
    return (ss.str().length());
}


int main(){
    std::cout << countdigits(99999999);
    return 0;
}