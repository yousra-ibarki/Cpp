#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


// int main()
// {
// 	// std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
// 	{
// 		// std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		ClapTrap a;
// 		ClapTrap b("Cody");

// 		// std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		a.attack("some other robot");
// 		a.takeDamage(10);
// 		// a.takeDamage(10);
// 		a.beRepaired(5);
// 		// a.attack("some other other robot");
// 		// b.beRepaired(3);
// 		// for (int i = 0; i < 12; i++)
// 		// 	b.attack("Cody-clone");
// 		// b.beRepaired(3);
// 		// std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 	}
// 	// std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
// 	{
// 		// std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		ScavTrap c;
// 		ScavTrap d("Savage");

// 		// std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		c.attack("CloneTrap");
// 		// for (int i = 0; i < 50; i++)
// 		// 	c.attack("CloneTrap");
// 		c.beRepaired(22);
// 		c.takeDamage(21);
// 		// c.beRepaired(22);
// 		c.guardGate();
// 		// c.guardGate();
// 		// d.attack("Savage-clone");
// 		// d.takeDamage(101);
// 		// d.takeDamage(15);
// 		// d.attack("ScavTrap-clone");
// 		// std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 	}
// 	return (0);
// }

int main()
{
    ClapTrap targ("Yousra");
    targ.attack("Hiba");
    targ.takeDamage(4);
    targ.beRepaired(3);

    ScavTrap hel("khadija");
    hel.attack("Yousra");
    hel.takeDamage(19);
    hel.beRepaired(29);
}