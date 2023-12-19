#include <iostream>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include <fstream>

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
        int repeat_str = 0;

        // std::cout << file_name << "\t" <<s1 << "\t" << s2 << std::endl;
       // open(av[1], O_RDWR);
        std::ifstream inputFile(file_name);
        std::ofstream outputFile(file_name+".replace");
        
        if(inputFile.is_open() && outputFile.is_open()){
           while(std::getline(inputFile, line)){
                outputFile << line << std::endl;
                repeat_str += line.find(s1);
                //std::cout << "["<< line << "]" << std::endl;
           }
            inputFile.close();
            outputFile.close();
            std::cout << repeat_str;
        }
    }
}
