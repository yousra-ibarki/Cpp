#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <map>
#include <sstream>

class Bitcoin
{
private:
    std::map<std::string, std::string> data;
    std::map<std::string, std::string>::iterator it;
    std::string line;
    std::ifstream file;
    std::string arr[3];
    double rate;
    std::string tokenKey;
    std::string tokenValue;

public:
    Bitcoin();
    ~Bitcoin();

    Bitcoin(const Bitcoin &obj);
    Bitcoin &operator=(const Bitcoin &obj);

    std::map<std::string, std::string> split(std::string str);

    void pars(char *str);

    int checkDate(std::string &date);

    int checkValue(double value, std::string &date);

    double getValue(std::string &date);

    std::string removeSpace(std::string str);

    int ft_check();
};

#endif