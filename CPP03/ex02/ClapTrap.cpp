#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& newName) : name(newName)
{
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap's Constructor Called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap's Destructor Called\n";
}

ClapTrap::ClapTrap(){
    this->name = "Def_Boot";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "Default Constructor Called\n";
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

ClapTrap::ClapTrap(ClapTrap& cpyObj)
{
    std::cout << "Copy Constructor Called\n";
    *this = cpyObj;
}


void ClapTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints -= 1;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage! he has now " << this->energyPoints << " energy points and " << this->hitPoints << " hit points" << std::endl;
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
