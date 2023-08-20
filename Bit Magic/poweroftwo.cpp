#include <iostream>
/* ------------My Solution before hint------------------
int countsetbits(const int &n){
    int count{};
    int copy{n};
    while(copy > 0){
        copy = (copy &(copy-1));
        ++count;
    }
    return count;
}

bool ispoweroftwo(const int &n){
    return (countsetbits(n) == 1) ;         //Time Complexity = Theta(No of set bits) 
}
-----------My solution after hint on Brian Kerningam's Algorithm------------
*/
bool ispoweroftwo(const int &n){        //Time Complexity = Theta(1), Constant
    if(n == 0)
        return false;   
    return ((n&(n-1)) == 0);       //Brian Kerningam's Algorithm
}

int main(){
    std::cout << std::boolalpha << ispoweroftwo(10);
}