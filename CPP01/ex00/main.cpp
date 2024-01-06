
#include "Zombie.hpp"

int main()
{
    Zombie *zom = newZombie("Shambler");
    //std::cout << zom->get_value() << "\n";
    zom->announce();
    randomChump("Vexmort");
}