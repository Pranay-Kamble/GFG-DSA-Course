#include <iostream>

int arr [] {2,3,5,4,6,1};
int arr_size = 6;
int modified_arr[6];

int getsum(int start, int end){
    if (start == 0)    //Time Complexity =  O(1), but preprocessing takes O(n) time
        return modified_arr[end];
    return modified_arr[end] - modified_arr[start-1];
}


int main(){
    modified_arr[0]= arr[0];
    for (int i{1}; i< arr_size; ++i){
        modified_arr[i] = modified_arr[i-1] + arr[i];
    }
    std::cout << getsum(0,2) << " " << getsum(1,3) << " " << getsum(2,6) << "\n";
    return 0;
}