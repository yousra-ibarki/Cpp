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
        std::cout << "AMateria Constructor" << std::endl;
    }
    ~AMateria(){
        std::cout << "AMateria Destructor" << std::endl;
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
        return old_type;
    }
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif