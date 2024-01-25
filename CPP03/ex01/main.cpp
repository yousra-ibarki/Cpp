#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


int main()
{
    ClapTrap obj("B0T-5000");

    std::cout << std::endl;

    obj.attack("Hiba");
    obj.takeDamage(4);
    obj.beRepaired(3);

    std::cout << std::endl;

    ScavTrap obj1("N3R0-TRON");

    std::cout << std::endl;

    obj1.attack("Yousra");
    obj1.takeDamage(19);
    obj1.beRepaired(29);
    obj1.guardGate();
    
    std::cout << std::endl;
}