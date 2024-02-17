#include "iter.hpp"

void print(double x){
    std::cout << x << std::endl;
}

int main(){
    int len = 2;
    int arr[2] = {9, 5};
    iter(arr, len, print);
}