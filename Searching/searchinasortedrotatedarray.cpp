#include <iostream>

int binarysearch(int arr[], int search, int low, int high){
    int mid {(low+high)/2};   //{100,500,10,20,30,40,50}

    while(low<=high){
        if (arr[mid] == search)
            return mid;
        else if (arr[mid] < search){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        mid = (low+high)/2;
    }
    return -1;
}

/*
--------------Naive Solution---------------
int searchinsortedrotated(int arr[], int size, int search){ //Time Complexity = O(n)
    for(int i {}; i<size; ++i){
        if (arr[i] == search)
            return i;
    }
    return -1;
}
-------------Better Solution (My Implementation)------------
int searchinsortedrotated(int arr[],int search,int low, int high){

    int mid {(low+high)/2};     //Time Complexity = O(log n)
                                
    if (arr[mid] == search)     //Auxiliary Space = O(log n) --> Due to recursive calls
        return mid;


    if (arr[mid] < arr[high]) { // If the right half is sorted

        if (( search <= arr[high] && search >= arr[mid+1] )) // and element is present in the sorted range
            return binarysearch(arr,search,mid+1,high);
        else  //and element is present in the left unsorted range
            return searchinsortedrotated(arr,search,low,mid-1);
    }
    else { // If left half is sorted 

        if (( search >= arr[low] && search <= arr[mid-1] ))// and element is present in the sorted range
            return binarysearch(arr,search,low,mid-1);
        else  //and the element is present in the right unsorted range
            return searchinsortedrotated(arr,search,mid+1,high);
    }

}

---------------Efficient Solution------------------------*/
int searchinsortedrotated(int arr[], int size, int search){
    int low {};
    int high {size-1};          //Time Complexity = O(log n)
    int mid {(low+high)/2};     //Auxiliary Space = O(1)

    while (low <= high){

        if (arr[mid] == search)
            return mid;

        else if (arr[mid] <= arr[high]){  //If the right half is sorted
            if ( arr[mid+1] <= search && search <= arr[high]) //and answer is present in the sorted right half
                low = mid+1; 
            else   // and answer is present in the unsorted left half
                high = mid-1;
        }

        else if (arr[mid] >= arr[low]){  //If the left half is sorted 
            if ( arr[low] <= search && search <= arr[mid-1]) //and answer is present in the sorted left half
                high = mid-1;
            else  // and answer is present in the unsorted right half
                low = mid+1;
        }

        mid = (low+high)/2;
    }
    return -1;
}

int main(){
    int arr[] {100,200,300,400,20,30,40};
    int size {sizeof(arr)/sizeof(arr[0])};
    int search {50};
    std::cout << "The index of " << search << " in the array is " << searchinsortedrotated(arr,size,search);
    return 0;
}