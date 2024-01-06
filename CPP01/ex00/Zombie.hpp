#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <dmalloc.h>

class Zombie{
private:
    std::string *name;
public:
    Zombie();
    ~Zombie();
    void set_value(const std::string &namee);
    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);


#endif