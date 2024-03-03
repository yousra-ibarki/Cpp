#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac > 1)
    {
        RPN obj;
        obj.parsFill(av);
        // obj.ft_RPN(av);
    }
    else{
        std::cout << "Error Enter a Polish Notation" << std::endl;
    }
    return 0;
}