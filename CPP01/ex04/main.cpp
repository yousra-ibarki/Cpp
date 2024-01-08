#include "sed.hpp"

int main(int ac, char **av)
{
    if (ac <= 3)
        std::cout << "Usage: ./program <filename> <s1> <s2>" << std::endl;
    else
    {
        std::string file_name = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string line;

        std::ifstream inputFile(file_name);
        std::ofstream outputFile(file_name+".replace");
        
        if(inputFile.is_open() && outputFile.is_open()){
           while(std::getline(inputFile, line)){
                    line = ft_replace(line, s2, s1);
                outputFile << line << std::endl;
           }
            inputFile.close();
            outputFile.close();
        }
    }
}
