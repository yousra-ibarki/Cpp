#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "Def_Boot";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "Default ScavTrap's Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap's Constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap's Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj)
{
    if (this != &obj)
    {
        this->attackDamage = obj.attackDamage;
        this->energyPoints = obj.energyPoints;
        this->hitPoints = obj.hitPoints;
        this->name = obj.name;
    }
    return *this;
}
ScavTrap::ScavTrap(ScavTrap const &obj)
{
    *this = obj;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now  in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints -= 1;
        std::cout << "ScravTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage! he has now " << this->energyPoints << " energy points and " << this->hitPoints << " hit points" << std::endl;
    }
    else if (this->energyPoints == 0)
        std::cout << "ScravTrap " << this->name << " cannot attack " << target << ", because he has no eneregy points " << this->energyPoints << std::endl;
    else
        std::cout << "ScravTrap " << this->name << " cannot attack " << target << ", because he has no hit points " << this->hitPoints << std::endl;
}
