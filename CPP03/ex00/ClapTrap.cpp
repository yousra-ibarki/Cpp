#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor Called\n";
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called\n";
}
ClapTrap::ClapTrap(ClapTrap &cpyObj)
{
    std::cout << "Copy Constructor Called\n";
    this->name = cpyObj.name;
    this->hitPoints = cpyObj.hitPoints;
    this->energyPoints = cpyObj.energyPoints;
    this->attackDamage = cpyObj.attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    if (energyPoints > 0)
        energyPoints -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " took " << amount << " amount of damage" << std::endl;
    if (hitPoints > 0)
        hitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " get " << amount << " amout of repaired points" << std::endl;
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints -= 1;
    }
}