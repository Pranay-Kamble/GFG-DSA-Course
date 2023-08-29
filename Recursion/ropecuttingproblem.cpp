#include <iostream>
                                                                                            
int maxropecuts(int n, int a, int b, int c){
    if (n < 0)                      //Time Complexity = O(3^n) ,better solution can be made using dynamic 
        return -1;                  //                                                        programming                           
    if (n == 0)
        return 0;
    int max {(maxropecuts(n-a,a,b,c))>(maxropecuts(n-b,a,b,c))?((maxropecuts(n-a,a,b,c))>(maxropecuts(n-c,a,b,c))?(maxropecuts(n-a,a,b,c)):(maxropecuts(n-c,a,b,c))):((maxropecuts(n-b,a,b,c))>(maxropecuts(n-c,a,b,c))?(maxropecuts(n-b,a,b,c)):(maxropecuts(n-c,a,b,c)))};
    if (max < 0)
        return -1;
    return 1+(max);
}
int main(){
    std::cout << maxropecuts(10,2,1,4);
    return 0;
}