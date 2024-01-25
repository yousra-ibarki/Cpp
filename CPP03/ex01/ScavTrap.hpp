#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
    ScavTrap();
    ScavTrap(ScavTrap const& obj);
    ScavTrap(std::string const name);
    ~ScavTrap();
    
    void attack(const std::string &target);
    ScavTrap& operator=(ScavTrap const& obj);

    void guardGate();
};


#endif
