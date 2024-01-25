#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ClapTrap obj("Blitzbot");
    std::cout << std::endl;

    obj.attack("Yousra");
    obj.takeDamage(4);
    obj.beRepaired(3);

    std::cout << std::endl;

    ScavTrap obj1("CircuitMaster");
    std::cout << std::endl;
    
    obj1.attack("Anas");
    obj1.takeDamage(19);
    obj1.beRepaired(29);
    obj1.guardGate();
    std::cout << std::endl;

    FragTrap obj2("Boltbot");
    std::cout << std::endl;

    obj2.attack("Noureddine");
    obj2.takeDamage(12);
    obj2.beRepaired(102);
    obj2.hightFivesGuys();
    
    std::cout << std::endl;

}

