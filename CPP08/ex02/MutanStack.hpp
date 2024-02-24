#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
template <class T>
class MutantStack : public std::stack
{
public:
    MutantStack(){
    }
    MutantStack(const MutantStack &obj){
        *this = obj;
    }
    ~MutantStack(){
    }
    MutantStack &operator=(const MutantStack &obj){
        if(this != &obj)
        {
            this->stackSize = obj.stackSize;
            //...
        }
    }

    void iterators();

};

#endif