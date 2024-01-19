#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ClapTrap obj("yousra");
    obj.attack("nourdin");
    obj.takeDamage(4);
    obj.beRepaired(3);

    ScavTrap obj1("khadija");
    obj1.attack("hibe");
    obj1.takeDamage(19);
    obj1.beRepaired(29);
    obj1.guardGate();

    FragTrap obj2("monaim");
    obj2.attack("yousra");
    obj2.takeDamage(12);
    obj2.beRepaired(102);
    obj2.hightFivesGuys();

}