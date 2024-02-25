#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>


class Bitcoin{
private:
    std::map<std::string, double> data;
    std::map<std::string, double>::iterator it;
    std::string line;
    std::ifstream file;

public:
    Bitcoin();
    ~Bitcoin();

    Bitcoin(const Bitcoin& obj);
    Bitcoin& operator=(const Bitcoin& obj);

    void split();


};

#endif