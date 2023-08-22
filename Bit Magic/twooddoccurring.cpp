#include <iostream>
/*
-----------Naive Approach---------------------
void twoodd(const int arr[] ,const int &size){      //Time Complexity = O(size*size) , Quadratic
    for (int i{}; i < size; ++i){
        int count {};
        for (int j{}; j < size ; ++j){
            if(arr[i] == arr[j])
                ++count;
        }
        if(count%2 != 0)
            std::cout << arr[i] << " ";
    }
}
------------Efficient Approach----------------
*/
void twoodd(const int arr[], int size){     //Time Complexity = Theta(n) + Theta(n) + Theta(n)== Theta(n)
    int num {};
    
    for (int i{0}; i < size ; ++i){
        num ^= arr[i];
    }
    int result {};
    int k {num & (~(num-1))};
    for (int i{}; i< size; ++i){
        if ((k & (arr[i])) == 0)
            result = result ^ arr[i];
    }
    std::cout << result << " ";
    result = 0;
    for (int i{}; i < size; ++i){
        if ((k & (arr[i])) != 0)
            result = result ^ arr[i];
    }
    std::cout << result ;
}

int main(){
    int arr[6] {6,5,5,1,6,9};
    twoodd(arr,6);
}
