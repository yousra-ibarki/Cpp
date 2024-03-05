#include "PmergeMe.hpp"

int main(int ac, char** av){

    if(ac == 2)
    {
    PmergeMe obj;

    obj.FordJohnson(av[1]);

    }
    else
        std::cout << "Error!" << std::endl;
    return 0;
}