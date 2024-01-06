#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
private:
    std::string *name;
public:
    Zombie();
    ~Zombie();
    void set_value(const std::string &namee);
    void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif