#include <iostream>

/*//-------------Brute Force-----------------
int subarraywithgivensum(int arr[], int size, int val){
    for (int k{size};k>=0; --k){  //Time Complexity = O(k * n)
        int sum {0};
        for(int i{}; i<k; ++i){// Applied sliding window with all possible values of k
            sum = sum + arr[i];
        }
        if (sum == val) 
            return true;
        for (int i{k}; i < size; ++i){
            sum = sum + arr[i] - arr[i-k];
            if (sum == val) 
                return true;
        }
    }
    return false;
}


//---------------Efficient Approach-------------------

  We intend to use the sliding window approach, but we do not know the value
  of k(size of the window) here.So we use variable k, which increases in size if the current sum
  is less than required sum and decreases if current sum is greater than the required sum

*/
int subarraywithgivensum(int arr[], int size, int sum){
    int start = 0;  
    int current_sum = 0;
    for (int end{}; end<size; ++end){   //Time Complexity = O(n) , Linear
        current_sum = current_sum + arr[end];  // k = end - start (size of the window)
        while (current_sum > sum){            
            current_sum = current_sum - arr[start];
            ++start;
        }
        if(current_sum == sum)
            return true;
    }
    return false;
}

int main(){
    int arr[] {4,8,12,5};
    int size {sizeof(arr)/sizeof(arr[0])};
    int sum {5};
    std::cout << "Result: " << subarraywithgivensum(arr,size,sum) << '\n';
    return 0;
}