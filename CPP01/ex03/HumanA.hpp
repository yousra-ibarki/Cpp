#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

class HumanA
{
private:
    Weapon *weapon;
    std::string name;

public:
    HumanA(std::string new_name, Weapon new_type);
    // ~HumanA()
    // {
    //     delete weapon;
    // }
    // void setWeapon(const std::string new_name, Weapon new_type)
    // {
    //     name = new_name;
    //     //weapon->setType(new_type);
    //     weapon = &new_type;
    // }
    void attack();
};


#endif 