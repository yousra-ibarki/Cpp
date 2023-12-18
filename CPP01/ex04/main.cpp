#include <iostream>
#include <string>
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    if (ac <= 3)
        std::cout << "Error" << std::endl;
    else
    {

        std::string file_name = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
 

        // std::cout << file_name << "\t" <<s1 << "\t" << s2 << std::endl;
        open(av[1], O_RDWR | O_CREAT);
        
    }
}



#include <iostream>
#include <fstream>
#include <sstream>

void replaceContent(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "File " << filename << " not found." << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.replace(pos, s1.length(), s2);
        pos += s2.length();
    }

    std::ofstream outputFile(filename + ".replace");
    outputFile << content;

    std::cout << "Content of " << filename << " has been copied to " << filename + ".replace" << " with replacements." << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: ./program <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceContent(filename, s1, s2);

    return 0;
}