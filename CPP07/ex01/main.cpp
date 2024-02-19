#include "iter.hpp"

void print(int x, int y){
    std::cout << x + y << std::endl;
}

int (*pfun) (int x, int y) = nullptr;  


int main(){
    const int len = 5;
    int arr[5] = {1, 6, 21, 17, 10};
    iter(arr, len, pfun);
}