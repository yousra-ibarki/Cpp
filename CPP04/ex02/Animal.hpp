#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
// #include "Cat.hpp"

class Animal{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();

    Animal(const Animal& obj);
    Animal& operator=(const Animal& obj);

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif