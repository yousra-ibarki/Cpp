#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    if(N < 0)
        exit(1);
    Zombie *zombie = new Zombie[N];
    for(int i = 0; i < N; i++){
        zombie[i].setName(name);
        std::cout << i + 1 << "\t";
        zombie[i].announce();
    } 
    return zombie;
}