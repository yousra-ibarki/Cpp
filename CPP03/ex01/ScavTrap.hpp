#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
    ScavTrap(std::string name, ClapTrap& obj);
    ~ScavTrap();
    ScavTrap& operator=(ScavTrap const& obj);
   ScavTrap(ScavTrap const& obj);


    void guardGate();
//     void updateAttribute(ClapTrap& obj){
//         std::cout << obj.getVal() << std::endl;
//         obj.setVal(100, 50, 20);
//         std::cout << obj.getVal() << std::endl;
//    }
};


#endif
