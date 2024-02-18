#include <iostream>

int max_consecutive_ones(int arr[], int size){ //Time Complexity = Theta(n)  
    int last_count {}, current_count{};
    for(int i{}; i<size; ++i){
        if(arr[i] == 1)
            ++current_count;
        else{
            last_count = (last_count > current_count ? last_count : current_count);
            current_count = 0;
        }   
    }
    last_count = (last_count > current_count ? last_count : current_count);
    return last_count; //if the last element is also 1, then else condition would not have been executed and 
                       //max consecutive may be not correct so we explicitly perform the condition again
}

int main(){
    int arr[] {0,1,1,1,0,1,1};
    int size {sizeof(arr)/sizeof(arr[0])};
    std::cout << max_consecutive_ones(arr,size) << std::endl;
}