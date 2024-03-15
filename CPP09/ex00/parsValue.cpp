#include "BitcoinExchange.hpp"

std::string Bitcoin::removeSpace(std::string str)
{
    std::string result;

    bool spaceFound = false;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if (*it == ' ')
        {
            if (!spaceFound)
            {
                result += *it;
                spaceFound = true;
            }
        }
        else
        {
            result += *it;
            spaceFound = false;
        }
    }
    return result;
}

void Bitcoin::splitParsValue()
{
    int count = 0;
    this->it = data.find(tokenKey);
    tokenValue = removeSpace(tokenValue);

    if ((this->tokenValue == "\0") && tokenKey == "\0")
        return;
    if (flag == 1)
    {
        std::cout << "Error: Invalid Input " << tokenKey << std::endl;
        return;
    }
    {
        std::string tok;
        int count  = 0;
        std::istringstream iss(tokenValue);
        while (getline(iss, tok, ' '))
            count++;
        if(count != 2)
        {
            std::cout << "Error: bad input => " << tokenValue << std::endl;
            return ;
        }
    }
    if (this->tokenValue == " value ")
        return;
    
    if (this->tokenValue == "\0" || this->tokenValue[tokenValue.length() - 1] == '-')
    {
        std::cout << "Error: bad input => " << this->arr[0] << "-" << this->arr[1] << "-" << this->arr[2] << std::endl;
        return;
    }
    for (int i = 0; tokenValue[i]; i++)
    {
        if (tokenValue[i] == '.')
            count++;
        if (!(std::isdigit(tokenValue[i])) && tokenValue[i] != '-' && tokenValue[i] != ' ' && tokenValue[i] != '.')
        {
            std::cout << "Error: bad input => " << tokenValue << std::endl;
            return;
        }
        if (count > 1)
        {
            std::cout << "Error: bad input =>" << tokenValue << std::endl;
            return;
        }
    }
    float nbr = std::atof(this->tokenValue.c_str());
    if (nbr < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    else if (nbr > 1000)
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
            std::cout << arr[0] << "-" << arr[1] << "-" << arr[2] << " => " << tokenValue << " = " << result << std::endl;
            return;
        }
        if (this->tokenKey == "date ")
            return;
        result = nbr * std::atof(data[this->tokenKey].c_str());
        std::cout << tokenKey << " => " << tokenValue << " = " << result << std::endl;
        return;
    }
    return;
}