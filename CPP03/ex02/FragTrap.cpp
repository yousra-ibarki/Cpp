#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->name = "Def_Boot";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "Default ScavTrap's Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap's Constructor Called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap's Constructor Called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &obj)
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
FragTrap::FragTrap(FragTrap const &obj)
{
    *this = obj;
}

void FragTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints -= 1;
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage! he has now " << this->energyPoints << " energy points and " << this->hitPoints << " hit points" << std::endl;
    }
    else if (this->energyPoints == 0)
        std::cout << "FragTrap " << this->name << " cannot attack " << target << ", because he has no eneregy points " << this->energyPoints << std::endl;
    else
        std::cout << "FragTrap " << this->name << " cannot attack " << target << ", because he has no hit points " << this->hitPoints << std::endl;
}

void FragTrap::hightFivesGuys(void)
{
    std::cout << "Give Me High Fives 🙏." << std::endl;
}