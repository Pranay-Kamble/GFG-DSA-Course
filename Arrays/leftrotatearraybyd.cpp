#include <iostream>
//Sir's solution ,,, I could not solve this problem
void reversearray(int arr[], int low, int high){
    while(low < high){ //basic swapping function which runs for 'size/2' times
        int copy {arr[low]};
        arr[low] = arr[high];
        arr[high] = copy;
        ++low;
        --high;
    }
}

void leftrotatearraybyd(int arr[], int size, int rotate){
    reversearray(arr, 0,rotate-1); //rotate the first 'd' elements
    reversearray(arr,rotate,size-1); //rotate the next remaining elements
    reversearray(arr,0,size-1); //rotate the whole array
}

int main(){
    int arr[] {1,2,3,4,5};
    leftrotatearraybyd(arr,sizeof(arr)/sizeof(arr[0]),2);
    for(int i{}; i<sizeof(arr)/sizeof(arr[0]); ++i){
        std::cout << arr[i] << ' ';
    }
    return 0;
} 