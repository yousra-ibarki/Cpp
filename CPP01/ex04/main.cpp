#include <iostream>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include <fstream>


std::string ft_replace(int pos, std::string line, std::string str){
    // std::cout << pos << std::endl;
    // std::cout << "this is the output" << "\t" << line[pos] << std::endl;
   // for(int j = 0; j < strlen(line.c_str()); j++){
        for(int i = 0; i < strlen(str.c_str()); i++){
            line[pos] = str[i];
            i++;
            pos++;
        }
    //}
    return line;
}

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
        const char *linee;
        int repeat_str = 0;

        std::ifstream inputFile(file_name);
        std::ofstream outputFile(file_name+".replace");
        
        if(inputFile.is_open() && outputFile.is_open()){
           while(std::getline(inputFile, line)){
                line = ft_replace(line.find(s1), line, s2);
                outputFile << line << std::endl;
           }
            inputFile.close();
            outputFile.close();
        }
    }
}
