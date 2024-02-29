#include "BitcoinExchange.hpp"


int main(int ac, char **av){

    // (void)av;
    if(ac != 2)
    {    
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    else{
        Bitcoin obj;

        obj.split(av[1]);
    }
}
