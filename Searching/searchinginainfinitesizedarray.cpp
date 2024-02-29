#include <iostream>
int binary_search(int arr[], int search, int low, int high){
    int mid {(low+high)/2};
    while (low <= high){
        if (arr[mid] == search)
            return mid;
        else if (arr[mid] < search)
            low = mid+1;
        else
            high = mid-1;
        mid = (low+high)/2;
    }
    return -1;
}


/*
----------Naive Solution----------
int searchininfinitesizearray(int arr[], int search){
    int i {};
    while(true){
        if (arr[i] == search)
            return i;
        if (arr[i] > search)
            return -1;
        ++i;
    }
}
-------------Efficient Approach--------------------*/
int searchininfinitesizearray(int arr[], int search){ //Time Complexity = O(log n)
    if (arr[0] == search)
        return 0;
    int i {1};
    while(arr[i] < search)
        i *= 2;
    
    if (arr[i] == search)
        return i;
    
    return binary_search(arr,search,(i/2) + 1, i-1);
}


int main(){
    int arr[] {1,10,15,20,40,80,90,100,120,500};//...... goes on till infinite size
    int search {100};
    std::cout << "The index of " << search << " in array is " << searchininfinitesizearray(arr,search)<<std::endl;
    return 0;
}