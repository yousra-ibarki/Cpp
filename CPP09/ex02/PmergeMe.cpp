#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
        return *this; // modifier
    return *this;
}

bool PmergeMe::isnumber(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::parsfill(std::string &input)
{
    std::istringstream string(input);

    for (unsigned long i = 0; input[i]; i++)
    {
        if (!std::isdigit(input[i]) && input[i] != ' ')
        {
            std::cout << "Error: " << input[i] << " is not a number" << std::endl;
            exit(1);
        }
    }
    while (getline(string, tokenV, ' '))
    {
        if (isnumber(tokenV) == true && tokenV != "\0")
            dataV.push_back(std::atoi(tokenV.c_str()));
    }
}

void PmergeMe::display()
{
    for (itV = dataV.begin(); itV != dataV.end(); itV++)
        std::cout << *itV << " ";
    std::cout << std::endl;
}

void PmergeMe::FordJohnson(std::string str)
{
    odd = true;
    parsfill(str);
    // std::cout << "before : ";
    // display();
    // std::cout << "size " << dataV.size() << std::endl;
    if(dataV.size() % 2 == 0)
        odd = false;
    if(odd == true)
    {
        this->lastValue = dataV.back(); 
        dataV.pop_back();
        display();  //remove later
    }
    for(itV = dataV.begin() ; itV != dataV.end() ; itV++)
    {
        itV++;
        int tmp = *itV;
        itV--;
        pairV = std::make_pair(*itV, tmp);
        if(*itV > tmp)
            pairV.swap()
        std::cout << "first " << pairV.first << " second " << pairV.second << std::endl;
        itV++;
    }
    display();
    

}