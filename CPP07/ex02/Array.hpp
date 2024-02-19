#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array{
private:
    T *arr;
public:
    Array(){
        arr= new T; 
    };

    Array(unsigned int n){
        arr = new T[n];
    }

    Array(const Array& obj){
        *this = obj;
    }

    Array& operator=(const Array& obj){
        (void)obj;
        return *this;
    }

    unsigned int size() const{
        unsigned int i = 0;
        while(arr[i])
            i++;
        return i;
    }
    ~Array(){

    };

};

#endif