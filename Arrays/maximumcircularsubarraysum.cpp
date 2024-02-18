//We get circular subarrays by connecting the last element to the first element of the array

/*
Approach:
*Maximum sum of normal subarrays =By normal method(kadane's method -> check if addition of current elem is max or not)
*Maximum sum of circular subarrays = Total Array sum - Minimum sum of the subarray
*Return the max of both sums */

#include <iostream>

int maxsumofcircularsubarray(int arr[], int size){  //Time Complexity = Theta(n) + Theta(n) + Theta(n) = Theta(n)
    int arr_sum {};
    for (int i{}; i<size; ++i){
        arr_sum += arr[i];
    }

    int sum {};
    int max_sum {arr[0]};
    
    for (int i{}; i<size; ++i){   //Finding the normal subarray sum, similar to kadane's algo(my code)
        sum += arr[i];
        sum = std::max(sum,arr[i]);
        max_sum = std::max(max_sum,sum);
    }
    if (max_sum < 0)    //If the max sum of normal subarray is negative (only possible when all elements are -ve)
        return max_sum; //then while calculating the circular sum the minimum sum will be equal to the array sum ,
                        // which will give answer as 0 , so we return the max value here only
    sum = 0;
    int min_sum {arr[0]};
    
    for (int i{}; i<size; ++i){  //Finding the minimum sum using modified similar kadane's algorithm
        sum += arr[i];
        sum = std::min(arr[i], sum);
        min_sum = std::min(sum, min_sum);
    }
    
    return std::max((arr_sum - min_sum), max_sum);
}

int main(){
    int arr[] {-5,-3};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout << maxsumofcircularsubarray(arr,size) << std::endl;
}