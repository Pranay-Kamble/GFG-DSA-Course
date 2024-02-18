#include <iostream>


/*//--------Brute Force Solution ----------------
int maxsumofkconsecutiveelements(int arr[], int size, int k){
    int max {};
    int sum = 0;
    for (int i{}; i < (size-k); ++i){ // Time Complexity = O(n * k)
        for (int j{i}; j<k+i; ++j){   //Auxiliary Space = O(1)
            sum = sum + arr[j];
        }
        max = std::max(sum, max);
        sum = 0;
    }
    return max;
}


//--------- Efficient Solution -------------- */
int maxsumofkconsecutiveelements(int arr[], int size, int k){  
    int sum {};
    for (int i{}; i<k ; ++i){  //Time Complexity = O(k) + O(n-k) = O(n)
        sum = sum + arr[i];    // Also known as sliding window technique
    }                          // We calculate the sum of current subarray using the
    int max {sum};             // sum of previous subarray without using loop
    for (int i{k}; i < size; ++i){ // and by only subtracting and addition of subarray elements
        sum = sum - arr[i-k] + arr[i];
        max = std::max(sum, max);
    }
    return max;
}

int main(){
    int arr[] {1,8,30,-5,20,7}; 
    int size {sizeof(arr)/ sizeof(arr[0])};
    int k{4};
    std::cout << maxsumofkconsecutiveelements(arr, size, k);
    return 0;
}