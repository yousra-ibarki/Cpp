#ifndef RPN_HPP
#define RPN_HPP

#include <iostream> 
#include <vector>

class RPN
{
private:
std::vector<std::string> polish;


public:
    RPN();
    RPN(const RPN &obj);
    ~RPN();
    RPN &operator=(const RPN &obj);

    // void ft_RPN(char** str);

    void parsFill(char** str);
};

#endif
