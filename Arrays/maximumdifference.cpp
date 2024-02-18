#include <iostream>

// int maxdiff(int arr[], int size)
// {//Time Complexity = O(n*n) , not efficient
//     int max {arr[1] - arr[0]};
//     for(int i{}; i<size-1; ++i){
//         for(int j{i+1}; j<size; ++j){
//             if((arr[j] - arr[i]) > max)
//                 max = arr[j] - arr[i];
//         }
//     }
//     return max;
// }

int maxdiff(int arr[], int size)
{//Time Complexity = O(n)

    int min{arr[0]};
    int result {arr[1] - arr[0]};
    for(int j{1}; j<size; ++j){
        if(arr[j]-min > result)
            result = arr[j]-min;

        min = (min > arr[j]?arr[j]:min);
    }
    return result;
}

int main(){
    int arr[] {30,10,8,2};
    std::cout << maxdiff(arr,sizeof(arr)/sizeof(arr[0])) << std::endl;
}