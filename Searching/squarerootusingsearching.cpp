#include <iostream>

int squareroot(int n){

    if (n == 1)
        return 1;
        
    int low {0};
    int high {n};
    int mid { (low+high)/2 };
    int ans {};

    while (low <= high){

        mid = (low+high)/2;
        int power = mid*mid;
        if (power > n)
            high = mid-1;
        else if (power < n){
            low = mid+1;
            ans = mid;
        }
        else
            return mid;
    }
    return ans;
}

int main(){
    int num {16};
    std::cout << "The floor of square root of " << num << " is " << squareroot(num);
    return 0;
}