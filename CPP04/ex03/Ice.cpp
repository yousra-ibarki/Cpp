#include "Ice.hpp"

Ice::Ice()
{
    this->old_type = "ice";
};
Ice::Ice(const Ice &obj)
{
    *this = obj;
};
Ice &Ice::operator=(const Ice &obj)
{
    if (this != &obj)
        this->old_type = obj.old_type;
    return *this;
};
Ice::~Ice(){

};

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots am ice bolt at " << target.getName() << std::endl;
}

