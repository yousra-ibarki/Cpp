#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat's Constructor" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat's Destructor" << std::endl;

}

WrongCat::WrongCat(const WrongCat& obj){
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj){
    if(this != &obj)
        this->type = obj.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
   }