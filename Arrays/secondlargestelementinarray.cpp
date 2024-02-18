#include <iostream>
/*
------------Naive Approach---------------
int secondlargestof(int arr[], int size)
{
    int maxindex{};             //Time Complexity = O(n), but two for loops present
    for (int i{1}; i < size; ++i)
    {
        if (arr[maxindex] < arr[i])
        {
            maxindex = i;
        }
    }
    int secondindex{-1};
    for (int i{1}; i < size; ++i)
    {
        if (arr[i] != arr[maxindex])
        {
            if (secondindex == -1)
                secondindex = i;
            else if (arr[secondindex] < arr[i])
                secondindex = i;
        }
    }
    return secondindex;
}

-------------Efficient Approach------------------*/
int secondlargestof(int arr[], int size){
    int max {};
    int secondmax {-1};         //Time Complexity = O(n), only one for loop
    for(int i{1}; i<size; ++i){
        if(arr[i] > arr[max]){
            secondmax = max;
            max = i;
        }
        if(arr[i] != arr[max]){
            if(secondmax == -1){
                secondmax = i;
            }
            secondmax = (arr[secondmax] > arr[i]? secondmax : i);
        }
    }
    return secondmax;
}

int main()
{
    int arr[]{25,25};
    std::cout << secondlargestof(arr, 2);
    return 0;
}