#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl{
private:
    char arr[4][8];
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    typedef void (Harl::*FPtr)();
    FPtr arrr[4];

    Harl();
    void complain(std::string level);
};

#endif