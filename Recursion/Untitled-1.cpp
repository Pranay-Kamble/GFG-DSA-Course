#include <iostream>
/* 
int towerofhanoi(int n,int result = 0){
    if(n == 0){             //Returns only the minimum number of moves required to solve for n disks
        return result;                                                              
    }                                               
    return towerofhanoi(n-1,result=(result*2)+1); //Tail Recursive
}
                       <--Start-->    <-Destination->  <-Auxiliary-->   */
int count {1};
void towerofhanoi(int n , char A = 'A' , char y = 'C' ,   char z = 'B'){
    if (n == 1){
        std::cout << count++ <<") Move disk "<< n << " from " << x << " to " << y << ".\n";
        return;
    }
    towerofhanoi(n-1, A , 'B' ,'C');
    std::cout << count++<<") Move disk " << n << " from " << x << " to " << y <<".\n";
    towerofhanoi(n-1,'B','C','A'); 
}

int main(){
    towerofhanoi(2);
}