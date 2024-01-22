#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string old_type;
    
public:
    AMateria(){
    }
    virtual ~AMateria(){
    }
    AMateria& operator=(const AMateria& obj){
        this->old_type = obj.old_type;
    }

    AMateria(std::string const &type)
    {
        old_type = type;
        std::cout << "AMateria Constructor" << std::endl;
    }

    std::string const &getType() const
    {
        return this->old_type;
    }
    virtual AMateria *clone() const = 0;

    virtual void use(ICharacter &target){
        (void)target;
    };
};

#endif