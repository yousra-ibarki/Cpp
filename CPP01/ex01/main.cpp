#include "Zombie.hpp"

Zombie::Zombie(){
    name = new std::string;
}
Zombie::~Zombie(){
    delete name;
}
void Zombie::set_value(const std::string &namee){
    *name = namee;
}
    // std::string get_value() const{
    //     return *name;
    // }
void Zombie::announce(void){
    std::cout << *name << std::endl;
}

int main()
{
    int n = 10;
    zombieHorde(n, "Gravemind");
}