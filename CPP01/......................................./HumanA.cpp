#include "HumanA.hpp"

HumanA::HumanA(const std::string& new_name, Weapon& new_type):weapon(new_type) 
{
    name = new_name;
}
HumanA::~HumanA(){
}
void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}