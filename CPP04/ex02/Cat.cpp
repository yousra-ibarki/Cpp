#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat's Constructor" << std::endl;
    this->type = "Cat";
    this->CatBrain = new Brain();
}

Cat::~Cat()
{
    delete CatBrain;
    std::cout << "Cat's Destructor" << std::endl;

}

Cat::Cat(const Cat &obj)
{
    std::cout << "Cat's Copy Constructor" << std::endl;
    this->type = obj.type;
    this->CatBrain = new Brain(*obj.CatBrain);
}

Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        this->Animal::operator=(obj);
        if (this->CatBrain)
            delete this->CatBrain;
        this->CatBrain = new Brain(*obj.CatBrain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}

Brain* Cat::getBrain() const{
    return this->CatBrain;
}