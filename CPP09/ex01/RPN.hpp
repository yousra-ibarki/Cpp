#ifndef RPN_HPP
#define RPN_HPP

#include <iostream> 
#include <stack>
#include <cctype>
#include <cstdlib>
#include <sstream>

class RPN
{
private:
    std::stack<float> polish;
public:
    RPN();
    RPN(const RPN &obj);
    ~RPN();
    RPN &operator=(const RPN &obj);

    void parsFill(std::string str);

    void display() ;
};

#endif
