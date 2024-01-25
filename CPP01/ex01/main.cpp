#include "Zombie.hpp"

int main()
{
   int n = 48;
    Zombie *zombie;
    zombie = zombieHorde(n, "Gravemind");
    if (!zombie)
        return 0;
      for(int i = 0; i < n; i++){
        std::cout << i + 1 << "\t";
        zombie[i].announce();
    } 
    delete [] zombie;
}