#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    int i = 1;
    if(ac == 2)
        std::cerr << "Error: cannot sort one number" << std::endl;
    else if (ac > 2)
    {
        PmergeMe obj;

        obj.FordJohnson(ac, av);
        i++;
    }
    else
        std::cout << "Error!" << std::endl;
    return 0;
}