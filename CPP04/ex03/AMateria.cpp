#include "AMateria.hpp"

AMateria::AMateria()
{
}
AMateria::~AMateria()
{
}
AMateria &AMateria::operator=(const AMateria &obj)
{
    if(this != &obj)
        this->old_type = obj.old_type;
    return *this;
}

AMateria::AMateria(std::string const &type)
{
    old_type = type;
    std::cout << "AMateria Constructor" << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->old_type;
}
void AMateria::use(ICharacter &target)
{
    (void)target;
}