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

std::map<std::string, std::string> Bitcoin::split(std::string str)
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
    return this->data;
    file.close();
}

std::string Bitcoin::ft_split(std::string str){
    std::string token;
    std::istringstream iss(str);
    while(getline(iss, token, '|'))
        std::cout << token << std::endl;
    return token;
}

void Bitcoin::pars(char* str){
    this->file2.open(str);
    while(this->file2.eof() == false){
        std::getline(this->file2, this->line);
        // std::cout << this->line << std::endl;
       ft_split(line);
    }
}

void Bitcoin::display(){
    for(this->it = this->data.begin(); it != this->data.end(); it++){
        std::cout << it->first << " , " << it->second << std::endl;
    }
}