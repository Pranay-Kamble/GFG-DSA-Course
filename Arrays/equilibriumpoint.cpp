#include <iostream> 

int arr[] {3,4,8,-9,9,7};
int size = sizeof(arr)/sizeof(arr[0]);

// bool equilibriumpoint(int modified_arr[], int size){
//     for (int i{}; i< size; ++i){
//         if ((i == 0 ) && (0 == (modified_arr[size-1] - modified_arr[0]))){
//             return 1;
//         }
//         if ((i == size-1 ) && (0 == modified_arr[size-2])){
//             return 1;
//         } 
//         if (modified_arr[i-1] == modified_arr[size-1] - modified_arr[i] )
//             return 1;
//     }
//     return 0; 
// }

bool equilibriumpoint(int arr[], int size){
    int sum {};
    for(int i{}; i< size; ++i){
        sum += arr[i];
    }
    int current_sum {};
    for (int i{}; i<size; ++i){
        sum -= arr[i];
        if (sum == current_sum)
            return true;
        current_sum += arr[i];
    }
    return false;
}

int main(){
    for (int i:arr){
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << std::boolalpha << "Result: " << equilibriumpoint(arr, size);
    return 0;
}