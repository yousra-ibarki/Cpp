#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog's Constructor" << std::endl;
    this->type = "Dog";
    this->DogBrain = new Brain();

}

Dog::~Dog()
{
    delete this->DogBrain;
    std::cout << "Dog's Destructor" << std::endl;
}


Dog::Dog(const Dog& obj)
{
    std::cout << "Dog's Copy Constructor" << std::endl;
   this->type = obj.type;
   this->DogBrain = new Brain(*obj.DogBrain);
}


Dog& Dog::operator=(const Dog& obj){
    if (this != &obj)
    {
        this->Animal::operator=(obj);
        if (this->DogBrain)
            delete this->DogBrain;
        this->DogBrain = new Brain(*obj.DogBrain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}

Brain* Dog::getBrain() const{
    return this->DogBrain;
}
