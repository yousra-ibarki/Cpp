#include "BitcoinExchange.hpp"

void Bitcoin::splitParsKey()
{
    year = 0;
    month = 0;
    days = 0;
    std::string tokenDate;
    flag = 0;
    std::istringstream iss(this->tokenKey);
    int i = 0;
    tokenDate = removeSpace(tokenKey);
    if(tokenDate == "date " || this->tokenKey == "\0" || this->tokenKey == "date" || tokenDate == " date ")
        return ;
    while (getline(iss, tokenDate, '-') && i < 3)
    {
        this->arr[i] = tokenDate;
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
        flag = 1;
        return;
    }
    if (this->arr[1].length() == 2 && (this->arr[1][0] == '0' || this->arr[1][0] == '1'))
    {
        month = std::atoi(this->arr[1].c_str());
        if (month < 1 || month > 12)
        {
            flag = 1;
            return;
        }
    }
    else
    {
        flag  = 1;
        return;
    }
    this->arr[2] = removeSpace(this->arr[2]);
    if (this->arr[2].length() == 3 && (this->arr[2][0] == '0' || this->arr[2][0] == '1' || this->arr[2][0] == '2' || this->arr[2][0] == '3'))
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
        return;
    }
    return;
}

