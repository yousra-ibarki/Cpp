#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <iostream>


template <typename T>
T add(T num1, T num2) {
   return (num1 + num2);
}

template <typename T>
void swap(T arg1, T arg2){
    T tmpArg;
    tmpArg = arg2;
    arg2 = arg1;
    arg1 = tmpArg;
}

template <typename T>
T min(T arg1, T arg2){
    if(arg1 < arg2)
        return arg1;
    else
        return arg2;
}

template <typename T>
T max(T arg1, T arg2){
    if(arg1 < arg2)
        return arg2;
    else
        return arg1;
}

#endif