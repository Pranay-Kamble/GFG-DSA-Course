#include <iostream>

/*
void leaders(int arr[], int size)
{ // Time Complexity = O(n*n), not efficient
    for (int i{}; i < size - 1; ++i)
    {
        bool button{0};
        for (int j{i + 1}; j < size; ++j)
        {
            if (arr[j] >= arr[i])
            {
                button = true;
                break;
            }
        }
        if (button == false)
            std::cout << arr[i] << ' ';
    }
    std::cout << arr[size - 1];
}
*/

void leaders(int arr[], int size)
{//Time Complexity = O(n), only drawback is it prints the leaders in the reverse order
    int current_leader = arr[size-1];
    std::cout << current_leader << ' ';
    for(int i{size-2}; i >= 0; --i){
        if(arr[i] > current_leader){
            current_leader = arr[i];
            std::cout << current_leader << ' ';
        }
    }
}

int main()
{
    int arr[]{0,1,2,34,5,6,7,8,9};
    leaders(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}