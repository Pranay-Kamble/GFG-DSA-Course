#include <iostream>

/*
-------------------My Approach-----------------
int countsetbits(const int &n){     //Time Complexity = Theta(No of bits)
    unsigned int x {1};             //Auxiliary Space = Theta(1)
    int count {};
    do {
    if((n&x)!= 0)
        ++count;
    }
    while(x <<= 1);
    return count;
}
-------------------Sir's Approach---------------

int countsetbits(const int &n){     //Time Complexity = Theta(No of bits till Mean Set Bit)
    int copy {n};                   //Mean Set Bit -> Last set bit on the left side
    int count {};
    while(copy > 0){
        count += (copy & 1);//Check if last bit is set, if it is set then the AND operator will return value 1
        copy >>= 1;           //which is added to count
    }
    return count;
}
---------------By Brian Kerningam's Algorithm-------------
*/
int countsetbits(const int &n){   //Time Complexity = Theta(No of set bits)
    int count {};                 //In this algorithm, we invert every set bit by doing AND operator on num and num-1
    int copy {n};                 //  n = 5 --> 0000.....0101 , n-1 = 4 --> 0000.....0100
    while (copy > 0){             //  (n & (n-1)) == 0000.....0100  --> the first set bit got inverted
        ++count;                  //  we will continue this till all set bits are inverted which will set the original number to 0 at last and then stop
        copy = (copy & (copy-1)); //Copy -1 ==> will set all bits before the first set bit to 1 and the first set bit to 0
    }
    return count;
}


int main() {
    std::cout << "Enter the number for which set bits are to be counted: ";
    int n {};
    std::cin >> n;
    std::cout << "Number of set bits in " << n<<" is " << countsetbits(n);
    return 0;
}