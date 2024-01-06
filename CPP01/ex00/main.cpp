
#include "Zombie.hpp"

int main()
{
    Zombie *zom = newZombie("Shambler");
    zom->announce();
    randomChump("Vexmort");
    delete zom;
}