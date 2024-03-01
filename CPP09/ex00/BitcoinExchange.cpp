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

std::map<std::string, double> Bitcoin::split(char *str)
{
    this->file.open(str);
    std::string token;
    while (this->file.eof() == false)
    {
        std::getline(this->file, this->line);
        std::istringstream iss(line);
        while(getline(iss, token, ',')){
            std::cout << "line " << token << std::endl;
            data.
        }
    }
    return this->data;
}
