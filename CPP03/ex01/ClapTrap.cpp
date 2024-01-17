#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap's Constructor Called\n";
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap's Destructor Called\n";
}
void ClapTrap::setVal(int newHitPoints, int newEnergyPoints, int newAttackDamage)
{
    hitPoints = newHitPoints;
    energyPoints = newEnergyPoints;
    attackDamage = newAttackDamage;
}
int ClapTrap::getVal()
{
    return attackDamage;
}
// ClapTrap(ClapTrap& cpyObj){
//     std::cout << "Copy Constructor Called\n";
//     this->name = cpyObj.name;
//     this->hitPoints = cpyObj.hitPoints;
//     this->energyPoints = cpyObj.energyPoints;
//     this->attackDamage = cpyObj.attackDamage;
// }

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints > 0)
        energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " took " << amount << " amount of damage" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints -= 1;
    }
    std::cout << "ClapTrap " << name << " get " << amount << " amout of repaired points" << std::endl;
}
