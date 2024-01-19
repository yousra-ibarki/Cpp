#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
public:
    ClapTrap(std::string newName);
    ClapTrap();
    ~ClapTrap();
    ClapTrap(ClapTrap& cpyObj);
    ClapTrap& operator=(ClapTrap const& obj1);


    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif