#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
private:
    T *arr;
    int _size;

public:
    Array() : arr(NULL), _size(0){};

    Array(unsigned int _size) : _size(_size)
    {
        arr = new T[_size];
    }

    Array(const Array &obj) : arr(NULL)
    {
        *this = obj;
    }

    Array &operator=(const Array &obj)
    {
        if (this->arr != NULL)
            delete[] this->arr;
        this->_size = obj._size;
        this->arr = new T[_size];

        for (int i = 0; i < this->_size; i++)
        {
            this->arr[i] = obj.arr[i];
        }
        return *this;
    }

    T &operator[](int i)
    {
        if (i >= this->_size || i < 0)
            throw Array::Exception();
        else
            return this->arr[i];
    }

    unsigned int size() const
    {
        return this->_size;
    }
    ~Array()
    {
        delete[] this->arr;
    };
    class Exception : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "invalid index";
        }
    };
};

#endif