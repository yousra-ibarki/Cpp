#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog's Constructor" << std::endl;
    type = "Dog";
    obj = new Brain();

}

Dog::~Dog()
{
    delete obj;
    std::cout << "Dog's Destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    *this = obj;
}


Dog& Dog::operator=(const Dog& obj){
    if(this != &obj)
        this->type = obj.type;
    return *this;
}