#include <iostream>
#include <string>
#include <iomanip>
#include <dmalloc.h>

class Zombie{
private:
    std::string *name;
public:
    Zombie(){
        name = new std::string;
    }
    ~Zombie(){
        std::cout << *name;
        delete name;
    }
    void set_value(const std::string &namee){
        *name = namee;
    }
    // std::string get_value() const{
    //     return *name;
    // }
    void announce(void){
        std::cout << *name << std::endl;
    }
};

Zombie *newZombie(std::string name){
    Zombie *zombie = new Zombie();
    zombie->set_value(name);
    return zombie;
}

void randomChump(std::string name){
    Zombie zombie;
    zombie.set_value(name);
   // std::cout << zombie.get_value() << std::endl;
   zombie.announce();
}

int main()
{
    Zombie *zom = newZombie("Shambler");
    //std::cout << zom->get_value() << "\n";
    zom->announce();
    randomChump("Vexmort");
}