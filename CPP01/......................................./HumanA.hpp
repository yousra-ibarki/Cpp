#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
    Weapon& weapon;
    std::string name;

public:
    HumanA(const std::string& new_name, Weapon& new_type);
    ~HumanA();
    void attack();
};


#endif 