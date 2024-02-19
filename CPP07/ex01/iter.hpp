#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Fp>
void iter(T *arr, T len, Fp funptr){
    if(!arr || !funptr)
        return ;
    for(int i = 0; i < len; i++)
    {
        funptr(arr[i], 1);
    }
}



#endif