#include <iostream>

unsigned int subsetsum(unsigned int sum, int arr[], int n){
    if(n == 0){
        return (sum == 0?1:0);
    }
    return (subsetsum(sum,arr,n-1) + subsetsum(sum-arr[n-1],arr,n-1));
}

int main(){
    int arr[] {10,20,15,5};
    std::cout << subsetsum(25,arr,4);
}