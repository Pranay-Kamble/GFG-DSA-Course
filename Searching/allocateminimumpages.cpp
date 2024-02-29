#include <iostream>

// *Minimize the maximum pages allocated between k students.
// *Only contiguous pages can be allocated.

/*
    The 
*/
bool isFeasible(int arr[], int size,int max_pages, int k){
    int current {};  //Checks for the numbers of students needed when a single student can read atmost max_pages
    int students {};
    for (int i {}; i<size; ++i){
        if (current + arr[i] > max_pages){  //Time Complexity = O(n)
            ++students;
            current = arr[i];
        }
        else
            current += arr[i];
    }
    if (students > k)
        return false;
    return true;
}

int minimum_pages(int arr[], int size, int k){
    int max {}, total_sum {};
    for (int i {}; i<size; ++i){ //Time Complexity = O(n * log(total_sum - max_element)) ~ O(n * log(total_sum))
        if (max < arr[i])
            max = arr[i];
        total_sum += arr[i];
    }
    if (k == 1)
        return total_sum;

    int low {max}, high {total_sum}, mid {(low + high)/2}, result {};

    while (low <= high){
        
        if (isFeasible(arr,size,mid,k)){
            result = mid;
            high = mid-1;  //If feasible, then ignore the right half
        }
        else
            low = mid + 1;
        mid = (low + high)/2;  //If not feasible, then ignore the left half

    }

    return result;
}


int main(){
    int arr[] {10,20,10,30};
    int size {sizeof(arr)/sizeof(arr[0])};
    int k {2};
    std::cout << "The maximum number of pages to be read by each student is " << minimum_pages(arr,size,k) << std::endl;
    return 0;
}