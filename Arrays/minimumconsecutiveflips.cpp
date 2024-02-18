#include <iostream>
/*
-----------Naive Approch--------------
void minflips(int arr[], int size)
{
    int ones = {}, zeroes = {};
    for (int i{}; i < size; ++i)
    {
        if (i == size - 1)
        {
            if (arr[i] == 0)
                ++zeroes;
            else
                ++ones;
        }
        if (arr[i] != arr[i + 1])
        {
            if (arr[i] == 0)
                ++zeroes;
            else
                ++ones;
        }
    }
    if (ones == 0 || zeroes == 0)
    {
        std::cout << "No need to flip any elements. " << std::endl;
    }
    else
    {
        std::cout << "Flip all the " << (ones > zeroes ? "Zeroes\n" : "Ones\n");
        int flip{ones > zeroes ? 0 : 1};
        for (int i{}; i < size; ++i)
        {
            if (i == 0)
            {
                if (arr[i] == flip & arr[i+1] != flip)
                {
                    std::cout << "From " << i << " to " << i << std::endl;
                }
            }
            
            else{
                if ((arr[i] == flip) & (arr[i - 1] != flip))
                {
                    std::cout << "From " << i << " to ";
                }
                if (i == size - 2)
                {
                    if (arr[i + 1] == flip)
                        std::cout << i + 1;
                }
                if ((arr[i] == flip) & (arr[i + 1] != flip))
                    std::cout << i << std::endl;
            }
            if(i == size-2){
                if (arr[i + 1] == flip)
                    std::cout << i <<std::endl;
            }
        }
    }
}
  
Efficient Approach Logic;
    The numbers will always differ in group by 1 or by 0 only
    the difference will be 0 if the first and last number are different
    the difference will be 1 if the first and last number are same
    if the difference in no of groups is 0, then dont flip
    else flip the other number ,which is not the first or last number 
    

-------------Efficient Approach---------------------
*/
void minflips(int arr[],int size){
    for (int i{1}; i<size; ++i){
        if(arr[i] != arr[i-1]){
            if(arr[i] != arr[0]){
                std::cout << "From "<< i << " to ";
            }
            else{
                std::cout << i-1;
            }
        }
    }
    if (arr[size-1] != arr[0]){//Prints the last index when there are equal number of groups
        std::cout << size-1 << std::endl;
    }
}

int main()
{
    int arr[]{0,0,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    minflips(arr, size);
}