#include <iostream>
using namespace std;

bool kthbit(const int &n, const int &k) // Sirs solution , I could not come up with a solution
{    
    auto x = 1 << (k-1);            //x will contain value which has kth bit set
    return (n&x != 0);
}

int main(){
    int n{}, k{};
    std::cout << "Enter n and k seperated by space:";
    std::cin >> n , k;
    std::cout << std::boolalpha << kthbit(n,k);   //n = 5 => 000......0101
}                                                 //k = 3 ,  x = 1<<(3-1) = 1 << 2 = 000......0001 << 2
                                                  //           = 000......0100 -> Kth bit is set
                                                  // n & x =  000......0101
                                                  //       &  000......0100
                                                  //          -------------
                                                  //          000......0100 -->4->Non Zero Value->kth bit is set
                                                  //          -------------