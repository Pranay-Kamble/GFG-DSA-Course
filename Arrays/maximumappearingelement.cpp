#include <iostream>
/*
 Approach;
 We first create an array of maximum size, in this array we mark the start of a range from the 
 left array as 1 and end of a range+1 (+1 is because the the end is also included in the range)
 as -1. We find the prefix sum and return the index of maximum value,
 this is the maximum appearing element.
*/
int maximumappearingelement(int left[], int right[],  int size){
    int preprocess[100] {};  //Given constraint on the max value is 100 
    for (int i{}; i<size; ++i){
        preprocess[left[i]] = 1;
        preprocess[right[i] + 1] = -1;
    }
    int result {0};
    for (int i{1}; i< 100; ++i){   //Prefix sum for preprocessed array
        preprocess[i] = preprocess[i-1] + preprocess[i];
        result = (preprocess[i] > preprocess[result])? i : result ;
    }
    return result;
}

int main(){
    int left[] {1,2,4};
    int right[] {4,5,7};
    int size {sizeof(left)/sizeof(left[0])};
    std::cout << "Maximum appearing element is " << maximumappearingelement(left, right, size) << '\n';
}