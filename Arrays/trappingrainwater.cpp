#include <iostream>
/*
-------------Naive Approach-------------
int trap_rainwater(int arr[], int size){   //Time Complexity = Theta(n*n) 
    int result {};
    
    for (int i{1}; i<size-1; ++i){   //Logic -> find the highest block to the left and right of a block, 
        int lmax {arr[i]};       //and subtract the height of current block with the minimum of the lmax and rmax
        int rmax {arr[i]};

        for(int j{}; j<i ; ++j){   //Runs from 0 to n-(max block)
            if(lmax < arr[j]){
                lmax = arr[j];
            }
        }

        for(int k{i} ; k< size; ++k){  //Runs from n-(max block) to size 
            if(rmax < arr[k]){
                rmax = arr[k];    //Both loops add to run till size
            }
        }

        result += (lmax>rmax?rmax:lmax) - arr[i];
    }
    
    return result;
}
----------Efficient Approach-------------*/
int trap_rainwater(int arr[], int size){   //Time Complexity = Theta(n) ,Linear Time
    int lmax[size], rmax[size];
    lmax[0] = arr[0];
    rmax[size-1] = arr[size-1];  //Compute all the lmax and rmax values for a specific index before hand
                                 // to reduce the time complexity to linear time
    for (int i {1}; i<size; ++i){
        lmax[i] = std::max(lmax[i-1],arr[i]);
    }
    for (int i{size-2}; i>=0; --i){
        rmax[i] = std::max(rmax[i+1], arr[i]);
    }

    int result {};
    for (int i{1}; i<size-1; ++i){
        result += std::min(lmax[i],rmax[i]) - arr[i];
    }

    return result;
}

int main(){
    int arr[] {10,0,0,0,10};
    int size {sizeof(arr)/ sizeof(arr[0])};
    std::cout << trap_rainwater(arr, size) << "\n";
    return 0;
}