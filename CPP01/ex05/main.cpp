#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        Harl obj;
        obj.complain(av[1]);   
    }
    else
        std::cout << "Usage: <debug/info/warning/error>" << std::endl;
}
