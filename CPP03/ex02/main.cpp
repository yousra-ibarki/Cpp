#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


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

    FragTrap heel("monaim", targ);
    heel.attack("yousra");
    heel.takeDamage(12);
    heel.beRepaired(102);
}