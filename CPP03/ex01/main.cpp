#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ClapTrap targ("yousra");
    targ.attack("nourdin");
    targ.takeDamage(4);
    targ.beRepaired(3);

    ScavTrap hel("khadija", targ);
    hel.attack("hibe");
    hel.takeDamage(19);
    hel.beRepaired(29);
}