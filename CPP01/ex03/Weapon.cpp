#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(const std::string& new_name){
    type = new_name; 
}
Weapon::~Weapon(){}
void Weapon::setType(std::string new_type)
{
    type = new_type;
}
const std::string &Weapon::getType(void) const
{
    return type;
}