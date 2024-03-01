#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
}

Bitcoin::~Bitcoin()
{
}

Bitcoin::Bitcoin(const Bitcoin &obj)
{
    *this = obj;
}

Bitcoin &Bitcoin::operator=(const Bitcoin &obj)
{
    if (this == &obj)
        return *this;
    else
    {
        this->it = obj.it;
        this->line = obj.line;
        //...
    }
    return *this;
}

std::map<std::string, std::string> Bitcoin::split(char* str)
{
    this->file.open(str);
    std::string token;
    std::string token1;
    while (this->file.eof() == false)
    {
        std::getline(this->file, this->line);
        std::istringstream iss(line);
        this->it = data.begin();
        getline(iss, token, ',');
        getline(iss, token1, ',');
        data[token] = token1;
    }
        // for(it = data.begin() ; it != data.end(); it++)
        //  {   std::cout << it->first << " = ";
        //     std::cout << it->second << std::endl;}
    return this->data;
}

v