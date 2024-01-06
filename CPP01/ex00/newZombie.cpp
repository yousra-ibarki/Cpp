#include "Zombie.hpp"

Zombie *newZombie(std::string name){
    Zombie *zombie = new Zombie();
    zombie->set_value(name);
    return zombie;
}
