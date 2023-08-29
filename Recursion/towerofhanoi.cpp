#include <iostream>
/* 
int towerofhanoi(int n,int result = 0){
    if(n == 0){             //Returns only the minimum number of moves required to solve for n disks
        return result;                                                              
    }                                               
    return towerofhanoi(n-1,result=(result*2)+1); //Tail Recursive
}
                          */
int count {1};
void towerofhanoi(int n , char source /*source*/ , char auxiliary/*destination*/ , char destination /*auxiliary*/){
    if (n == 1){
        std::cout << count++ <<") Move disk "<< n << " from " << source<< " to " << destination <<".\n";
        return;
    }
    towerofhanoi(n-1, source,destination,auxiliary);
    std::cout << count++<<") Move disk " << n << " from " << source << " to " << destination<<".\n";
    towerofhanoi(n-1,auxiliary,source,destination); 
}

int main(){
    towerofhanoi(4,'A','B','C');
}