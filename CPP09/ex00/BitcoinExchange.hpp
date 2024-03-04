#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <map>
#include <sstream>


class Bitcoin{
private:
    std::map<std::string, std::string> data;
    std::map<std::string, std::string>::iterator it;
    std::string line;
    std::ifstream file;
    std::ifstream file2;
    std::string arr[3];
    float result;
    int flag;
    int year;
    int month;
    int days;
    std::string tokenKey;
    std::string tokenValue;


public:
    Bitcoin();
    ~Bitcoin();

    Bitcoin(const Bitcoin& obj);
    Bitcoin& operator=(const Bitcoin& obj);

    std::map<std::string, std::string> split(std::string str);

    void splitParsKey();

    void splitParsValue();

    void pars(char *str);

    void display();

};

#endif