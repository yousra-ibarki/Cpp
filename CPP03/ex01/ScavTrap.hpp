#ifndef SCAVTRAP_HPP 
#define SCAVTRAP_HPP 

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
    ScavTrap(std::string name, ClapTrap& obj);
    ~ScavTrap();
    void guardGate();
    // void updateAttribute(ClapTrap& obj);
};

#endif