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
    ScavTrap& operator=(ScavTrap const& obj);

    void guardGate();
};


#endif
