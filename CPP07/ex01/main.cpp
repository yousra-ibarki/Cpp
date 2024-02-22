#include "iter.hpp"
template <typename T>
void print(T x, T y){
    std::cout << x + y << std::endl;
}

// template <typename T>
// void (*pfun) (T x, T y) = nullptr;  


int main(){
    const int len = 5;
    int arr[5] = {1, 6, 21, 17, 10};
    iter(arr, len, print<int>);
}