#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap's Constructor Called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap's Destructor Called\n";
}

ClapTrap::ClapTrap(){
}
ClapTrap& ClapTrap::operator=(ClapTrap const& obj1){
    if(this != &obj1)
    {
        this->name = obj1.name;
        this->hitPoints = obj1.hitPoints;
        this->energyPoints = obj1.energyPoints;
        this->attackDamage = obj1.attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(ClapTrap &cpyObj)
{
    std::cout << "Copy Constructor Called\n";
    *this = cpyObj;
}



void ClapTrap::attack(const std::string &target)
{
    if (energyPoints > 0)
        energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int  x = (4294967295 + amount) + 1;
   
    if(x < 0)
    {
        std::cout << "ClapTrap " << name << " didn't took damage because the amount is negatve "<< x << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " took " << amount << " amount of damage" << std::endl;
    if (hitPoints > 0)
        hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    int  x = (4294967295 + amount) + 1;
   
    if(x < 0)
    {
        std::cout << "ClapTrap " << name << " didn't get rapaired because the amount is negative " << x << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " get " << amount << " amout of repairing points" << std::endl;
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints -= 1;
    }
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
