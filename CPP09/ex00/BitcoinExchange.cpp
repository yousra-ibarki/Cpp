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

 std::map<std::string, double> Bitcoin::split(char* str)
{
    size_t start = 0;
    size_t end = 0;
    this->file.open(str);
    while (this->file.eof() == false)
    {
        while(end = str.find(" ", start))
        std::getline(this->file, this->line);
        std::cout << this->line << std::endl;
        // for (int i = 0; this->line[i]; i++)
        // {
            // this->data[i] = this->line[i];
        // }
        // for( this->it = data.begin(); this->it != data.end(); it++)
        //     std::cout << this->it->first << std::endl;
    }
}