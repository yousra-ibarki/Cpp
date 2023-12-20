#include <iostream>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include <fstream>


int ft_count(std::string line, std::string str1){
    int count = 0;
    int i = 0;
    int pos = 0;
    while(((pos = line.find(str1, pos)) != std::string::npos)){
      count++;
      pos += str1.size();
    }
   std::cout << count << std::endl;
    return count;
}

std::string ft_replace(int pos, std::string line, std::string str2, std::string str1){
    int count = ft_count(line, str1);
    for(int i = 0; i < count ; i++){
    line.insert(pos, str2);
    pos = line.find(str1);
    line.erase(pos, strlen(str1.c_str()));
    }
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
        int pos;

        std::ifstream inputFile(file_name);
        std::ofstream outputFile(file_name+".replace");
        
        if(inputFile.is_open() && outputFile.is_open()){
           while(std::getline(inputFile, line)){
                pos = line.find(s1);
               if(pos != std::string::npos)
                    line = ft_replace(pos, line, s2, s1);
                outputFile << line << std::endl;
           }
            inputFile.close();
            outputFile.close();
        }
    }
}
