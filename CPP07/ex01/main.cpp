#include "iter.hpp"

int main(){
    int arr[6] = {1, 6, 21, 17, 10, 12};
    iter(arr, 6, print<int>);
}
