#include "BitcoinExchange.hpp"


int main(int ac, char **av){

    if(ac != 2)
    {    
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    else{
        // std::map<std::string, double> data;
        // std::map<std::string, double>::iterator it;

        // std::string line;
        // std::ifstream file;

        file.open(av[1]);
        std::string sep = ",";
        // while(file.eof() ==  false)
        // {
            std::getline(file, line);
            std::cout << line << std::endl;
            for(int i = 0; line[i] ; i++){
                data[i] = line[i];
            }
            for( it = 0; it != data.end(); it++)
                std::cout << it->first << std::endl;
        // }
    }
}
