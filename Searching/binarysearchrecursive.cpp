#include <iostream>

int binarysearch(int arr[], int size, int search, int low = 0){
    int high {size-1};
    if (low > high)
        return -1;

    int mid {(low+high)/2};
    if (arr[mid] == search)
        return mid;

    if (arr[mid] > search)
        return binarysearch(arr, mid, search, low);
    else 
        return binarysearch(arr, size, search, mid+1);
    
}
 
int main(){
    int arr[] {10,20,30,40,50,60};
    int size {sizeof(arr)/sizeof(arr[0])};
    int search {60};
    std::cout << "Return value is " << binarysearch(arr,size,search) << '\n';
    return 0;
}