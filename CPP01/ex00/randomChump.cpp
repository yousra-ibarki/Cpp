#include "Zombie.hpp"

void randomChump(std::string name){
    Zombie zombie;
    zombie.set_value(name);
   // std::cout << zombie.get_value() << std::endl;
   zombie.announce();
}