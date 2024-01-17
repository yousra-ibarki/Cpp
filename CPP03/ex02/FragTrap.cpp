#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name, ClapTrap &obj1) : ClapTrap(name)
{
    obj1.setVal(100, 100, 30);
    std::cout << "FragTrap's Constructor Called" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap's Constructor Called" << std::endl;
}

void FragTrap::hightFivesGuys(void)
{
    std::cout << "Give Me High Fives 🙏🏻" << std::endl;
}