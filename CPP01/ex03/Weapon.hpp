#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon
{
private:
    std::string type;

public:
    Weapon(const std::string& new_name);
    ~Weapon();
    void setType(std::string new_type);
    const std::string &getType(void) const;
};

#endif 