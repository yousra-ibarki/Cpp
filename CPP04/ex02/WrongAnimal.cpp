#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal's Constructor." << std::endl;
}

 WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal's Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj){
    *this = obj;
}

void WrongAnimal::makeSound() const{
    std::cout << "Tweet Tweet!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    if(this != &obj)
        this->type = obj.type;
    return *this;
}

std::string WrongAnimal::getType() const{
        return type;
}