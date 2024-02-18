#include <iostream>
//-----------Search Operation-----------------
int search(int find,int arr[], int size){
    for (int i{}; i<size; ++i)      //Time Complexity = O(n)
        if(arr[i] == find)
            return i;
    return -1;
}

//----------Insert Operation------------------
std::string insert(int arr[], int size , int filled, int position , int x){
    if(filled == size){
        return "No empty indexes in the Array";         //Time Complexity = O(n - (filled-position)) ~ O(n)
    }
    int insertindex = position -1;
    for (int i{filled-1}; i >= insertindex; --i ){
        arr[i+1] = arr[i];
    }
    arr[insertindex] = x;
    return "Inserted into the specified position\n";
}

//----------Delete Operation------------------
bool deletevalue(int arr[], int size, int filled,int value, int empty = 0){
    int deletedindex = -1;
    for (int i{}; i<filled;++i){
        if(arr[i] == value){
            deletedindex = i;
            --filled; //since, one element is being deleted, the occupied elements is reduced by one
            break;
        }
    }
    if(deletedindex == -1){
        return false;
    }
    for(int i{deletedindex}; i<filled; ++i){
        arr[i] = arr[i+1];
    }
    arr[filled] = empty;
    return true;
}

int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    std::cout << std::boolalpha << deletevalue(arr,10,9,10,-1) << '\n';
    for (int i{}; i<10 ;++i){
        std::cout << arr[i] << " ";
    }
    return 0;
}