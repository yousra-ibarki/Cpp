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
        this->data = obj.data;
        // this->file2 = obj.file2;
        this->result = obj.result;
    }
    return *this;
}

std::map<std::string, std::string> Bitcoin::split(std::string str)
{
    this->file.open(str);
    std::string tokenValue;
    std::string tokenKey;
    while (this->file.eof() == false)
    {
        std::getline(this->file, this->line);
        std::istringstream iss(line);
        this->it = data.begin();
        getline(iss, tokenValue, ',');
        getline(iss, tokenKey, ',');
        data[tokenValue] = tokenKey;
    }
    return this->data;
    file.close();
}

int Bitcoin::splitParsKey()
{
    std::string tokenValue;
    int nbr;
    std::istringstream iss(this->tokenKey);
    int i = 0;
    if (this->tokenKey == "date" || this->tokenKey == "\0")
        return 0;
    while (getline(iss, tokenValue, '-') && i < 3)
    {
        this->arr[i] = tokenValue;
        i++;
    }
    if (this->arr[0].length() == 4)
    {
        nbr = std::atoi(this->arr[0].c_str());
        if (nbr > 2022 || nbr < 2009)
        {
            // std::cout << "Error: bad input => " << this->arr[0] << "-" << this->arr[1] << "-" << this->arr[2] << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << this->arr[0] << " Invalid Input!" << std::endl;
        return 0;
    }
    if (this->arr[1].length() == 2 && (this->arr[1][0] == '0' || this->arr[1][0] == '1'))
    {
        nbr = std::atoi(this->arr[1].c_str());
        if (nbr < 1 || nbr > 12)
        {
            std::cout << this->arr[1] << " is an Invalid Input!" << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << this->arr[1] << " Invalid Input!" << std::endl;
        return 0;
    }
    if (this->arr[2].length() == 2 && (this->arr[2][0] == '0' || this->arr[2][0] == '1' || this->arr[2][0] == '2' || this->arr[2][0] == '3'))
    {
        nbr = std::atoi(this->arr[1].c_str());
        if (nbr < 1 || nbr > 31)
        {
            std::cout << this->arr[2] << " is an Invalid Input!" << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << this->arr[2] << " Invalid Input!" << std::endl;
        return 0;
    }
    return 0;
}

int Bitcoin::splitParsValue()
{
    this->it = data.find(tokenKey);

    if (this->tokenValue == "value")
        return 0;
    float nbr = std::atof(this->tokenValue.c_str());
    if(this->tokenValue == "\0" && tokenKey == "\0")
        return 0;
    if (this->tokenValue == "\0")
    {
        std::cout << "Error: bad input => " << this->arr[0] << "-" << this->arr[1] << "-" << this->arr[2] << std::endl;
        return 0;
    }

    if (nbr < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    if (this->tokenValue.length() > 10 || (this->tokenValue.length() >= 10 && this->tokenValue[this->tokenValue.length() - 1] > '7'))
    {
        std::cout << "Error: too large number." << std::endl;
        return 0;
    }
    else
    {
        if (it == data.end())
        {
            data.insert(std::pair<std::string, std::string>(tokenKey, ""));
            this->it = data.find(tokenKey);
            --it;
            data.erase(tokenKey);
            result = nbr * std::atof(it->second.c_str());
            std::cout << tokenKey << " => " << tokenValue << " = " << result << std::endl;
            return 0;
        }
        if(this->tokenKey == "date")
            return 0;
        result = nbr * std::atof(data[this->tokenKey].c_str());
        std::cout << tokenKey << " => " << tokenValue << " = " << result << std::endl;
        return 0;
    }
    return 0;
}

void Bitcoin::pars(char *str)
{
    this->file2.open(str);
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

void Bitcoin::display()
{
    for (this->it = this->data.begin(); it != this->data.end(); it++)
    {
        std::cout << it->first << " , " << it->second << std::endl;
    }
}