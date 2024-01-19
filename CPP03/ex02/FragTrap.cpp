#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
    setVal(100, 100, 30);
    std::cout << "Default ScavTrap's Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
    setVal(100, 100, 30);
    std::cout << "FragTrap's Constructor Called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap's Constructor Called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const& obj)
{
    if(this != &obj)
        FragTrap::operator=(obj);
    return *this;
}
FragTrap::FragTrap(FragTrap const &obj)
{
    *this = obj;
}

void FragTrap::hightFivesGuys(void)
{
    std::cout << "Give Me High Fives 🙏." << std::endl;
}