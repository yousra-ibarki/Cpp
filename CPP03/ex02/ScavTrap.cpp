#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name, ClapTrap &obj) : ClapTrap(name)
{
    obj.setVal(100, 50, 20);
    std::cout << "ScavTrap's Constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap's Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now  in Gate keeper mode." << std::endl;
}
//     void updateAttribute(ClapTrap& obj){
//         std::cout << obj.getVal() << std::endl;
//         obj.setVal(100, 50, 20);
//         std::cout << obj.getVal() << std::endl;
//    }
