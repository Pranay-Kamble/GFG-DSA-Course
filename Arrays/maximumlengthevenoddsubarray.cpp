//Ques-We need to find the maximum length of a subarray that contains consecutive odd and even alternating elements

#include <iostream>
//My approach - Efficient Approach 
int max_evenodd_subarray(int arr[], int size){  //Time Complexity = Theta(n), Linear
    int result {};
    int count {1};
    for (int i {}; i<size-1; ++i){
        if (((arr[i]%2) == 0) == (!((arr[i+1]%2) == 0)))  //True if element at i and i+1 are of not both odd or even
            ++count;
        else{
            result = std::max(count,result);
            count = 1;
        }
    }
    result = std::max(count,result);
    return result;
}

int main(){
    int arr[] {5,10,20,6,3,8};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout << max_evenodd_subarray(arr,size) << std::endl;
}