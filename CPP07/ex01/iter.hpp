#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Fp>
void iter(T *arr, int len, Fp funptr)
{
    if (!arr || !funptr)
        return;
    for (int i = 0; i < len; i++)
    {
        funptr(arr[i]);
    }
}

template <typename T>
void print(T x)
{
    std::cout << (x += 1) << std::endl;
}



#endif