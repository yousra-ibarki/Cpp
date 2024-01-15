#include "Zombie.hpp"

Zombie::Zombie(){
    name = "";
}
Zombie::~Zombie(){
    std::cout << name << std::endl;
}
void Zombie::setName(const std::string &name){
        this->name = name;
}
void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}