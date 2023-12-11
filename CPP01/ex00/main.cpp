#include <iostream>
#include <string>
#include <iomanip>

class Zombie{
private:
std::string name;


public:

Zombie(std::string str_name){
    name = str_name;
}

void announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...";
}

};

Zombie* newZombie(std::string name)
{
    Zombie zombie = Zombie(name);;
'
'}

int main()
{
    Zombie zombie("Foo");

    zombie.announce();

}