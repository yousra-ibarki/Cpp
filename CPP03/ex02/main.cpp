#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ClapTrap obj("Yousra");
    obj.attack("Nourdin");
    obj.takeDamage(4);
    obj.beRepaired(3);

    ScavTrap obj1("Khadija");
    obj1.attack("Hibe");
    obj1.takeDamage(19);
    obj1.beRepaired(29);
    obj1.guardGate();

    FragTrap obj2("Monaim");
    obj2.attack("Yousra");
    obj2.takeDamage(12);
    obj2.beRepaired(102);
    obj2.hightFivesGuys();

}