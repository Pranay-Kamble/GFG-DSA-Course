#include <iostream>
#include <vector>

void findprimes(const int &num){                //Time Complexity = Theta(root(n) * n) + Theta(n)
    std::vector <bool> list (num+1 , true);     //               => Theta(n * root(n)) 
    for(int i {2} ; i*i <= num ; ++i){
        if (list.at(i)){
            for(int j {i*2}; j <= num; j +=i){
                list.at(j) = false;
            }
        }
    }
    for (int i{2} ; i<num ; ++i){
        if(list.at(i)){
            std::cout << i << " ";
        }
    }
}

int main(){
   findprimes(200);
    return 0;
} 