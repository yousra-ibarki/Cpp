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
        this->data = obj.data;
        this->it = obj.it;
        this->line = obj.line;
        this->result = obj.result;
        this->flag = obj.flag;
        this->year = obj.year;
        this->days = obj.days;
        this->tokenKey = obj.tokenKey;
        this->tokenValue = obj.tokenValue;
    }
    return *this;
}

std::map<std::string, std::string> Bitcoin::split(std::string str)
{
    this->file.open(str);
    std::string tokenValue;
    std::string tokenKey;
    if(this->file.is_open())
    {
        while (this->file.eof() == false)
        {
            std::getline(this->file, this->line);
            std::istringstream iss(line);
            this->it = data.begin();
            getline(iss, tokenValue, ',');
            getline(iss, tokenKey, ',');
            data[tokenValue] = tokenKey;
        }
        file.close();
        return this->data;
    }
    else
    {
        std::cerr << "cannot open the file" << std::endl;
        exit(1);
    }   
}

bool Bitcoin::isnumber(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}


void Bitcoin::pars(char *str)
{
    this->file2.open(str);
    if (file2.is_open())
    {
        while (this->file2.eof() == false)
        {
            std::getline(this->file2, this->line);
            std::istringstream iss(line);
            getline(iss, tokenKey, '|');
            getline(iss, tokenValue, '|');
            splitParsKey();
            splitParsValue();
            tokenKey.clear();
            tokenValue.clear();
        }
    }
    else
        std::cout << "No such file" << std::endl;
}
