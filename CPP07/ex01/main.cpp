#include "iter.hpp"

int add(){
    int a = 2;
    int b= 5;
    return a = a + b;
}

int main(){

     int len = 2;
    int arr[2] = {0,2};
    ::iter(&arr, len, add);
}