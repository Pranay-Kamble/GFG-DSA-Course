#include <iostream>

/*--------Naive Approach------------
int lastoccurrence(int arr[], int size, int search){
    for(int i{}; i<size; ++i){
        if (arr[i] > search)
            return -1;

        if (i != size-1){
            if (arr[i] == search && arr[i+1] != search)
                return i;
        }
        else{
            if (arr[i] == search)
                return i;
            return -1;
        }
    }
    return -1;  //Will never reach here, just added to keep warning of compiler away
}

-------------Another Naive approach-------------
int lastoccurrence(int arr[], int size, int search){ // Return the first occurrence from the back
    for (int i{size-1}; i>=0; --i){
        if (arr[i] < search)
            return -1;
        if (arr[i] == search)
            return i;
    }
    return -1;
}

------------Efficient Approach (Recursive)-----------
int lastoccurrence(int arr[], int size, int search, int low, int high){  //Time Complexity = O(log n)
    if (low > high)                                                      //Auxiliary Space = O(log n)
        return -1;

    int mid {(low+high)/2};

    if (arr[mid] == search){
        if (mid == size-1|| arr[mid+1] != search)
            return mid;
        else{
            return lastoccurrence(arr, size, search, mid+1, high);
        }
    }

    if (arr[mid] > search)
        return lastoccurrence(arr, size, search, low, mid-1);
    
    return lastoccurrence(arr, size, search, mid+1, high);
}

------------Efficient Approach (Iterative)-----------*/
int lastoccurrence(int arr[], int size, int search){
    int low {0}, high {size-1}, mid {(high+low)/2}; //Time Complexity = O(log n)
    while (low <= high){                            //Auxiliary Space = O(1 )
        if (arr[mid] == search){
            if (mid == size-1 || arr[mid+1] != search)
                return mid;
            else{
                low = mid+1;
                mid = (low+high)/2;
            }
        }

        if (arr[mid] > search){
            high = mid -1;
            mid = (low+high)/2;
        }

        if (arr[mid] < search){
            low = mid+1;
            mid = (low+high)/2;
        }
    }
    return -1;
}

int main(){
    int arr[] {0,5,8,8,10,10};
    int size {sizeof(arr)/ sizeof(arr[0])};
    int search {0};

    std::cout << "The occcurrence of " << search << " is "<<lastoccurrence(arr, size, search);
    return 0;
}