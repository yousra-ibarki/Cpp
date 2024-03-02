#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>


class Bitcoin{
private:
    std::map<std::string, std::string> data;
    std::map<std::string, std::string>::iterator it;
    std::string line;
    std::ifstream file;
    std::ifstream file2;

public:
    Bitcoin();
    ~Bitcoin();

    Bitcoin(const Bitcoin& obj);
    Bitcoin& operator=(const Bitcoin& obj);

    std::map<std::string, std::string> split(std::string str);

    std::string ft_split(std::string str);

    void pars(char *str);

    void display();

};

#endif