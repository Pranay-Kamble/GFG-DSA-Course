#include <iostream>

void frequenciesof(int arr[], int size)
{ // Time Complexity = O(n)
    int count{1};
    int current{arr[0]};
    if (size == 1)
    {
        std::cout << arr[0] << " 1" << std::endl;
        return;
    }
    for (int i{1}; i < size; ++i)
    {
        if (arr[i] == current)
        {
            ++count;
        }
        if (arr[i] > current)
        {
            std::cout << current << ' ' << count << std::endl;
            count = 1;
            current = arr[i];
        }
        if (i == size - 1)
        {
            std::cout << current << ' ' << count << std::endl;
            return;
        }
    }
}

int main()
{
    int arr[]{40, 50,50};
    int size{sizeof(arr) / sizeof(arr[0])};
    frequenciesof(arr, size);
}