#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    setVal(100, 50, 20);
    std::cout << "Default ScavTrap's Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name)
{
    setVal(100, 50, 20);
    std::cout << "ScavTrap's Constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap's Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj)
{
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}
ScavTrap::ScavTrap(ScavTrap const &obj)
{
    *this = obj;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
