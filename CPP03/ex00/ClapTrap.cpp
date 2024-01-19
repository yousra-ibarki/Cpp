#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->attackDamage = 0;
    this->hitPoints = 10;
    this->energyPoints = 10;
    std::cout << "Default Constructor Called\n";
}

ClapTrap::ClapTrap(std::string newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
    this->name = newName;
    std::cout << "Constructor Called\n";
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called\n";
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
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage! he has now " << this->energyPoints << " energy points and " << this->hitPoints << " hit points" << std::endl;
        this->energyPoints -= 1;
    }
    else if(this->energyPoints == 0)
        std::cout << "ClapTrap " << this->name << " cannot attack " << target << ", because he has no eneregy points " << this->energyPoints << std::endl;
    else   
        std::cout << "ClapTrap " << this->name << " cannot attack " << target << ", because he has no hit points " << this->hitPoints << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{   
    if (this->hitPoints > amount)
        this->hitPoints -= amount;
    else if(this->hitPoints > 0)
        this->hitPoints = 0;
    std::cout << "ClapTrap " << name << " took " << amount << " amount of damage he has now " << this->hitPoints << " hit poits" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->hitPoints += amount;
        this->energyPoints -= 1;
        std::cout << "ClapTrap " << name << " get " << amount << " amout of repairing points he has now " << this->energyPoints << " energy points and " << this->hitPoints << " hit points" << std::endl;
    }
    else if(this->energyPoints == 0)
        std::cout << "ClapTrap " << name << " cannot repair itself, because he has no energy points " << this->energyPoints << std::endl;
    else if(this->hitPoints == 0)
        std::cout << "ClapTrap " << name << " cannot repair itself, because he has no hit points " << this->hitPoints << std::endl;


}