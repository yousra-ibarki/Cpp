#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Fp>
void iter(T *arr, T len, Fp funptr){
    for(int i = 0; i < len; i++)
    {
        funptr(arr[i]);
    }
}



#endif