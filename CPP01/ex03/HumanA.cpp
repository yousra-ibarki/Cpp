#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string new_name, Weapon new_type)
{
    name = new_name;
    //weapon->setType(new_type);
    weapon = &new_type;
}
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
void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}