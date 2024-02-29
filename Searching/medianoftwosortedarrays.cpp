#include <iostream>

void bubbleSort(int arr[], int size){
    int swapper {};
    for (int i {}; i<size ; ++i){
        for (int j {}; j<size-i-1; ++j){
            if (arr[j] > arr[j+1]){
                swapper = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swapper;
            }
        }
    }
}

// float medianOfTwoSortedArrays(int arr1[], int size1, int arr2[], int size2){
//     int sortedArr[size1+size2];
//     for (int i {}; i<size1; ++i){
//         sortedArr[i] = arr1[i];
//     }
//     for(int i {size1} ; i<size1+size2; ++i){
//         sortedArr[i] = arr2[i-size1];
//     }
//     bubbleSort(sortedArr,size1+size2);

//     if ((size1+size2) % 2 == 1 )
//         return sortedArr[(size1+size2)/2];
//     else{
//         return (float)((sortedArr[(size1+size2)/2] + sortedArr[((size1+size2)/2)-1] )/(2.0));
//     }
// }

double medianOfTwoSortedArrays(int arr1[], int size1, int arr2[], int size2){
    int n1 {std::min(size1,size2)} , n2{std::max(size1,size2)};
    int *small_arr {((size1 <= size2) ? arr1 : arr2)};
    int *large_arr {small_arr == arr1 ? arr2 : arr1};

    int low {}, high {n1-1};


    while (low <= high){
        int i1{(low+high)/2};
        int i2 {abs((n1+n2+1)/2) - i1};

        int min1 {(i1 == n1) ? INT_MAX : small_arr[i1]};
        int min2 {(i2 == n2) ? INT_MAX : large_arr[i2]};

        int max1 {(i1 == 0) ? INT_MIN : small_arr[i1-1]};
        int max2 {(i2 == 0) ? INT_MIN : large_arr[i2-1]};

        if (max1 <= min2 && max2 <= min1){
            if ((n1+n2) % 2 == 1){   
                return static_cast<double>(std::max(max1,max2));
            }
            else{
                return (( ( (std::max(max1,max2)) + (std::min(min1,min2)) ) / 2.0 ) );
            }
        }
        else if (min1 < max2)
            low = i1 + 1;
        else // if (min2 < max1)
            high = i1-1;

    }
    return -1;  //Will never reach this line , just written to avoid warnings
}

int main(){
    int arr1[] {30,40,50,60};
    int arr2[] {5,6,7,8,9};
    int size1 {sizeof(arr1)/sizeof(arr1[0])};
    int size2 {sizeof(arr2)/sizeof(arr2[0])};
    std::cout << "The result is " << medianOfTwoSortedArrays(arr1,size1,arr2,size2);

    return 0;
}