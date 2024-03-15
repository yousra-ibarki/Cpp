#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &obj)
{
    (void)obj;
    return *this;
}

void RPN::parsFill(std::string str)
{
    int i = 0;
    float nbr;
    std::string tmp;

    for (int i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
        {
            std::cout << "Error: bad input!" << std::endl;
            return;
        }
    }
    while (str[i])
    {
        if (std::isdigit(str[i]))
        {
            tmp = str[i];
            nbr = std::atof(tmp.c_str());
            polish.push(nbr);
        }
        else if(str[i] == '-' && std::isdigit(str[i + 1]))
        {
            i++;
            tmp = str[i];
            nbr = -1 * std::atof(tmp.c_str());
            polish.push(nbr);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            nbr = polish.top();
            polish.pop();

            if (str[i] == '+' && !polish.empty())
            {
                polish.top() = polish.top() + nbr;
            }
            else if (str[i] == '-' && !polish.empty())
            {
                polish.top() = polish.top() - nbr;
            }
            else if (str[i] == '*' && !polish.empty())
            {
                polish.top() = polish.top() * nbr;
            }
            else if (str[i] == '/' && !polish.empty())
            {
                polish.top() = polish.top() / nbr;
            }
        }
        i++;
    }
}

void RPN::display()
{
    if (polish.size() > 1)
    {
        std::cout << "Error: Bad Input!" << std::endl;
        return;
    }

    while (polish.size())
    {
        std::cout << polish.top() << std::endl;

        polish.pop();
    }
}
