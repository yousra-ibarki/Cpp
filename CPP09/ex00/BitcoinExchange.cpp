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

void Bitcoin::splitParsKey()
{
    year = 0;
    month = 0;
    days = 0;
    std::string tokenValue;
    flag = 0;
    std::istringstream iss(this->tokenKey);
    int i = 0;
    if (this->tokenKey == "date" || this->tokenKey == "\0")
        return;
    while (getline(iss, tokenValue, '-') && i < 3)
    {
        this->arr[i] = tokenValue;
        i++;
    }
    if (this->arr[0].length() == 4)
    {
        year = std::atoi(this->arr[0].c_str());
        if (year > 2022 || year < 2009)
        {
            flag = 1;
            return;
        }
    }
    else
    {
        std::cout << year << " Invalid Input!" << std::endl;
        return;
    }
    if (this->arr[1].length() == 2 && (this->arr[1][0] == '0' || this->arr[1][0] == '1'))
    {
        month = std::atoi(this->arr[1].c_str());
        if (month < 1 || month > 12)
        {
            std::cout << month << " month is Invalid!" << std::endl;
            return;
        }
    }
    else
    {
        std::cout << month << " Invalid Input!" << std::endl;
        return;
    }
    if (this->arr[2].length() == 2 && (this->arr[2][0] == '0' || this->arr[2][0] == '1' || this->arr[2][0] == '2' || this->arr[2][0] == '3'))
    {
        days = std::atoi(this->arr[2].c_str());
        if((year % 4 != 0 && month == 2 && days > 28) || days < 1)
            flag = 1;
        else if((year % 4 == 0 && month == 2 && days > 29) || days < 0)
            flag = 1;
        else if((month % 2 == 0 && month != 2 && days > 30) || days < 0)
            flag = 1;
        else if((month % 2 != 0 && days > 31) || days < 0)
            flag = 1;
    }
    else
    {
        flag = 1;
        // std::cout << tokenKey << "-" << tokenValue << " 1Invalid Input!" << std::endl;
        return;
    }
    return;
}

void Bitcoin::splitParsValue()
{
    this->it = data.find(tokenKey);

    if(flag == 1)
    {
        std::cout << tokenKey << " Error: invalid date" << std::endl;
        return ;
    }
    if (this->tokenValue == "value ") // stil thinking about the space
        return;
    if (this->tokenValue == "\0" && tokenKey == "\0")
        return;
    if (this->tokenValue == "\0" || this->tokenValue[tokenValue.length() - 1] == '-')
    {
        std::cout << "Error: bad input => " << this->arr[0] << "-" << this->arr[1] << "-" << this->arr[2] << std::endl;
        return;
    }
    for (int i = 0; tokenValue[i]; i++)
    {
        if (!(std::isdigit(tokenValue[i])) && tokenValue[i] != '-' && tokenValue[i] != ' ' && tokenValue[i] != '.')
        {
            std::cout << tokenValue << " Error: bad input" << std::endl;
            return;
        }
        if (tokenValue[i] == '.' && tokenValue[i + 1] == '.')
        {
            std::cout << tokenValue << " Error: bad input" << std::endl;
            return;
        }
    }
    float nbr = std::atof(this->tokenValue.c_str());
    if (nbr < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    if (this->tokenValue.length() > 10 || (this->tokenValue.length() >= 10 && this->tokenValue[this->tokenValue.length() - 1] > '7'))
    {
        std::cout << "Error: too large number." << std::endl;
        return;
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
            return;
        }
        if (this->tokenKey == "date")
            return;
        result = nbr * std::atof(data[this->tokenKey].c_str());
        std::cout << tokenKey << " => " << tokenValue << " = " << result << std::endl;
        return;
    }
    return;
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