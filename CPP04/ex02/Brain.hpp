#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain{
private:
    std::string ideas[100];

public:
    Brain();

    Brain(const Brain& obj);
    Brain& operator=(const Brain& obj);

    ~Brain();
};

#endif