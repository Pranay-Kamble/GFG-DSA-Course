#include <iostream>
#include <vector>
bool isprime(const int &num){
    if (num == 1){
        return false;
    }
    for(int i{2} ; i*i <= num ; ++i){
        if(num %i == 0){
            return false;
        }
    }
    return true;
}
/**/
void primefactors(const int &num){                  //Time Complexity = O( root (n) )
    if(isprime(num)){
        std::cout << num << " ";
        return;
    }
    for (int i{2}; i*i <= num;++i){
        if (isprime(i)){
            int copy = i ;
            while(num%copy == 0){
                std::cout << i << " ";
                copy *= i;
            }
        }
    }
}

// void primefactors(const int &num){
//     int temp = num;
//     if (isprime(num)){
//         std::cout <<num;
//         return;
//     }
//     for (int i {2} ; i*i <= num ; ++i){
//         while(temp%i == 0){
//             std::cout << i <<" ";
//             temp /= i;
//         }
//     }
// }


int main(){
    primefactors(450);
    return 0;
}