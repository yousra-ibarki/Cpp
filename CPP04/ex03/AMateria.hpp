#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
protected:
    std::string old_type;
    
public:
    AMateria();
    virtual ~AMateria();
    AMateria& operator=(const AMateria& obj);

    AMateria(std::string const &type);

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;

    virtual void use(ICharacter &target);
};

#endif