#include "Zombie.hpp"

int main()
{
    int n = 15;
    Zombie *zombie;
    zombie = zombieHorde(n, "Gravemind");
    delete [] zombie;
}