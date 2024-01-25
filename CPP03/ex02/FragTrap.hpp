#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
public:
    FragTrap();
    FragTrap(std::string const& name);
    FragTrap(FragTrap const& obj);
    ~FragTrap();
    FragTrap& operator=(FragTrap const& obj);

    void attack(const std::string& target);
    void hightFivesGuys(void);
};

#endif