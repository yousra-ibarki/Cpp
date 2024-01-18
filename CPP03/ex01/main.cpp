#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ClapTrap targ("Yousra");
    targ.attack("Hiba");
    targ.takeDamage(4);
    targ.beRepaired(3);

    ScavTrap hel("khadija", targ);
    hel.attack("hiba");
    hel.takeDamage(19);
    hel.beRepaired(29);
}