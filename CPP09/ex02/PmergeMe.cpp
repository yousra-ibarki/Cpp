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
            dataD.push_back(std::atoi(tokenV.c_str()));
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

void PmergeMe::FordJohnson(std::string str)
{
    odd = true;
    parsfill(str);
    sortVector();
    sortDeque();
}