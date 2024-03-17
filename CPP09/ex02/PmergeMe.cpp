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
    int i = 0;
    if(str[0] == '+')
        i++;
    for (; str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::parsfill(std::string input)
{
    if (PmergeMe::isnumber(input) && input != "\0")
    {
        dataV.push_back(std::atoi(input.c_str()));
        dataD.push_back(std::atoi(input.c_str()));
    }
    else
    {
        std::cerr << "Error!" << std::endl;
        exit(1);
    }
}

void PmergeMe::displayV()
{
    for (itV = dataV.begin(); itV != dataV.end(); itV++)
        std::cout << *itV << " ";
    std::cout << std::endl;
}

void PmergeMe::displayD()
{
    for (itD = dataD.begin(); itD != dataD.end(); itD++)
        std::cout << *itD << " ";
    std::cout << std::endl;
}

void PmergeMe::FordJohnson(int ac, char **av)
{
    odd = true;
    int i = 1;
    while (i < ac)
    {
        parsfill(av[i]);
        i++;
    }
    sortVector();
    sortDeque();
}