#include <iostream>

/*-------Brute Force----------
int firstoccurence(int arr[], int size, int search){
    for (int i{}; i<size; ++i){
        if (arr[i] == search)
            return i;
    }
    return -1;
}

---------Efficient Approach-----

-- Iterative Solution*/
int firstoccurence(int arr[], int size, int search)
{
    int low{0};
    int high{size - 1};
    int mid {(low+high) /2};
    while (low <= high)
    {
        if (arr[mid] == search){
            if (arr[mid-1] != search || mid == 0){
                return mid;
            }
            else{
                high = mid-1;
                mid = (low+high)/2;
            }
        }

        if (arr[mid] > search){
            high = mid -1;
            mid = (low + high)/2;
        }

        if (arr[mid] < search){
            low = mid +1;
            mid = (low+high)/2;
        }
    }
    return -1;
}

int firstoccurence(int arr[], int size, int search, int low, int high){
    if (low > high)
        return -1;
    int mid {(low+high)/2};

    if (arr[mid] == search){
        if (arr[mid-1] != search || mid == 0)
            return mid;
        else
            return firstoccurence(arr, size, search, low, mid-1);
        
    }

    if (arr[mid] > search)
        return firstoccurence(arr, size, search, low, mid-1);
    
    return firstoccurence(arr, size, search, mid+1, high);
}

int main()
{
    int arr[] {5,10,10,20,20};
    int size {sizeof(arr) / sizeof(arr[0])};
    int search {20 };
    std::cout << "Index Occurence of " << search << " is " << firstoccurence(arr, size, search,0 , size-1);
    return 0;
}