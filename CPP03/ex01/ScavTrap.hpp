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

    // void attack(const std::string &target);
    void guardGate();
//     void updateAttribute(ClapTrap& obj){
//         std::cout << obj.getVal() << std::endl;
//         obj.setVal(100, 50, 20);
//         std::cout << obj.getVal() << std::endl;
//    }
};


#endif
