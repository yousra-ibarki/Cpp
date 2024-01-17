#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
public:
    FragTrap(std::string name, ClapTrap& obj1);
    ~FragTrap();

    void hightFivesGuys(void);
};

#endif