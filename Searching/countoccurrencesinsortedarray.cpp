#include <iostream>


/*
------------Naive Approach-----------
int occurencesof(int arr[], int size, int search){   //Time Complexity = Linear = O(n)
    int count {};                                    //Auxiliary Space = Constant = O(1)
    for (int i{}; i<size; ++i){
        if (arr[i] == search)
            ++count;    
        if (arr[i] > search)  //Making use of the fact that the array is sorted
            break;
    }
    return count;
}

-----------Efficient Approach--------
int occurencesof(int arr[], int size, int search, int low, int high){  //Recursive
    if (low > high)       //Time Complexity = O(logn + k), where k is the number of occurences
        return 0;           
    int mid {(low+high)/2};

    if (arr[mid] == search)  
        return 1 + occurencesof(arr, size, search, low, mid-1) + occurencesof(arr, size, search, mid+ 1,high);
        //    returning current_match + any matches on the left subarray + any mathches on right subarray
    if (arr[mid] > search)
        return occurencesof(arr, size, search, low, mid-1);

    else         // (arr[mid] < search)
        return occurencesof(arr, size, search, mid+1, high);
    
}
*/

int firstoccurrence(int arr[], int size, int search){
    int low {};
    int high {size-1};
    int mid {(low+high)/2};
    while (low <= high){
        if (arr[mid] == search){
            if (mid == 0 || arr[mid-1] != search)
                return mid;
            else{
                high = mid-1;
                mid = (low+high)/2;
            }
        }

        else if (arr[mid] > search){
            high = mid-1;
            mid = (low+high)/2;
        }

        else{
            low = mid+1;
            mid = (low+mid)/2;
        }
    }
    return -1;
}

int lastoccurrence(int arr[], int size, int search){
    int low {};
    int high {size-1};
    int mid {(low+high)/2};
    while (low <= high){
        if (arr[mid] == search){
            if (mid == size-1 || arr[mid+1] != search)
                return mid;
            else{
                low = mid+1;
                mid = (low+high)/2;
            }
        }

        else if (arr[mid] > search){
            high = mid-1;
            mid = (low+high)/2;
        }

        else{
            low = mid+1;
            mid = (low+mid)/2;
        }
    }
    return -1;
}


int occurrencesof(int arr[], int size, int search){
    int first {firstoccurrence(arr,size,search)};
    if (first == -1)        //Time Complexity = O(logn) + O(logn) = O(logn)
        return 0;
    return (lastoccurrence(arr, size, search) - first + 1);
}


int main(){
    int arr[] {10,10,10,10,10};
    int size {sizeof(arr)/sizeof(arr[0])};
    int search {10};
    std::cout << "The number of occurrences of " << search << " is " << occurrencesof(arr,size,search) << '.';
}