#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array{
private:
    T *arr;
    int size;
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
        delete[] arr;
        arr = new arr;
        this->arr = obj.arr;
        return *this;
    }

    Array& operator[](int i){
        if(i > size)
            std::cout << "index out of bounds" << std::endl;
        else
            return arr[i];
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