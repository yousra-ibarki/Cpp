#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat's Constructor" << std::endl;
    type = "Cat";
    obj = new Brain();
}

Cat::~Cat()
{
    delete obj;
    std::cout << "Cat's Destructor" << std::endl;

}

Cat::Cat(const Cat& obj){
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj){
    if(this != &obj)
        this->type = obj.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
   }