#ifndef RPN_HPP
#define RPN_HPP

#include <iostream> 
#include <vector>
#include <cctype>
#include <cstdlib>
#include <sstream>

class RPN
{
private:


    int nbr;
    std::string input;

public:
    RPN();
    RPN(const RPN &obj);
    ~RPN();
    RPN &operator=(const RPN &obj);

    std::string &split();

    void calcul();

    void parsFill(char* str);

    void display() ;
};

#endif
