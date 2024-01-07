
#include "HumanB.hpp"

HumanB::HumanB(const std::string& new_name): weapon(NULL){
    name = new_name;
}
HumanB::~HumanB(){
}
void HumanB::setWeapon(Weapon& new_weapon){
    weapon = &new_weapon;
}
void HumanB::attack(){
    if(weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with their hands " << std::endl;
}