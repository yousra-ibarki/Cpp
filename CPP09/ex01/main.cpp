#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        RPN obj;
        obj.parsFill(av[1]);
        // obj.display();
        // obj.ft_RPN(av);
    }
    else{
        std::cout << "Error Enter a Polish Notation" << std::endl;
    }
    return 0;
}