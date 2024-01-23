#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Default";
    std::cout << "Animal's Constructor." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal's Destructor" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal's Copy Constructor" << std::endl;
    *this = obj;
}

void Animal::makeSound() const
{
    std::cout << "Quack Quack!" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}