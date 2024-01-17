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
    ClapTrap(std::string newName);
    ~ClapTrap();
    void setVal(int newHitPoints, int newEnergyPoints, int newAttackDamage);
    int getVal();
    // ClapTrap(ClapTrap& cpyObj){
    //     std::cout << "Copy Constructor Called\n";
    //     this->name = cpyObj.name;
    //     this->hitPoints = cpyObj.hitPoints;
    //     this->energyPoints = cpyObj.energyPoints;
    //     this->attackDamage = cpyObj.attackDamage;
    // }

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif