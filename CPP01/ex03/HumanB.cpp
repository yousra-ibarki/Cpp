#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string new_name){
    // weapon = new Weapon;
    name = new_name;
}
// ~HumanB()
// {
//     delete weapon;
// }
void HumanB::setWeapon(Weapon new_weapon){
    // name = new_name;
    weapon = &new_weapon;
}
void HumanB::attack(){
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}