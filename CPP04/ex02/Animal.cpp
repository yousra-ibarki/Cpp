#include "Animal.hpp"



Animal::Animal(){
    std::cout << "Animal's Constructor." << std::endl;
}

 Animal::~Animal(){
    std::cout << "Animal's Destructor" << std::endl;
}

Animal::Animal(const Animal& obj){
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
    if(this != &obj)
        this->type = obj.type;
    return *this;
}

std::string Animal::getType() const{
        return type;
}