
#include "Zombie.hpp"

// void function(){
//     system("leaks Brainz");
// }
int main()
{
    // atexit(function);
    Zombie *zom = newZombie("Shambler");
    zom->announce();
    randomChump("Vexmort");
    delete zom;
}