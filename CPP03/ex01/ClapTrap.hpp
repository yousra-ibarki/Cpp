#ifndef CLAPTRAP_HPP 
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
    ClapTrap(std::string const& newName);
    ~ClapTrap();
    ClapTrap();
    ClapTrap(ClapTrap &cpyObj);
ClapTrap& operator=(ClapTrap const& obj1);


    void setVal(int newHitPoints, int newEnergyPoints, int newAttackDamage);
    int getVal();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif