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

void PmergeMe::display2()
{
    for (it = data.begin(); it != data.end(); it++)
        std::cout << it->first << " " << it->second << " ";
    std::cout << std::endl
              << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::createPairsSorted()
{
    int tmp;
    std::pair<int, int> pairV;
    if (dataV.size() % 2 == 0)
        odd = false;
    if (odd == true)
    {
        this->lastValue = dataV.back();
        dataV.pop_back();
        // display(); // remove later
    }
    for (itV = dataV.begin(); itV != dataV.end(); itV++)
    {
        itV++;
        tmp = *itV;
        itV--;
        pairV = std::make_pair(*itV, tmp);
        if (pairV.first > pairV.second)
        {
            std::swap(pairV.first, pairV.second);
            // tmp = pairV.first;
            // pairV.first = pairV.second;
            // pairV.second = tmp;
        }
        data.push_back(pairV);
        itV++;
    }
    return data;
}

void PmergeMe::insertionSort(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].second > key.second)
        {
            pairs[j + 1] = pairs[j];
            j = j - 1;
        }
        pairs[j + 1] = key;
    }
}

// int PmergeMe::jacobsthalNbr(int len)
// {
//     int a = 3;
//     int b = 5;
//     int c;

//     if (len == 0)
//         return 3;
//     if (len == 1)
//         return 5;
//     for (int i = 2; i <= len; i++) {
//         c = b + 2 * a;
//         a = b;
//         b = c;
//     }
//     return b;
// }


void PmergeMe::binarySearch(){
    
}

void PmergeMe::mainPend(std::vector<std::pair<int, int> > &data)
{
    std::vector<int> mainS;
    std::vector<int>::iterator tmpit;

    std::vector<int> pend;

    int j = 0;
    for (it = data.begin(); it != data.end(); it++)
    {
        pend.push_back(it->first);
        mainS.push_back(it->second);
        j++;
    }

    mainS.insert(mainS.begin(), pend[0]);
    pend.erase(pend.begin());



    // int nbr;
    // for (unsigned long i = 0; i < pend.size(); i++)
    // {
    //     nbr = jacobsthalNbr(i);
    //     std::cout << "jacop " << nbr << std::endl;
    // }

    for (tmpit = mainS.begin(); tmpit != mainS.end(); tmpit++)
        std::cout << " main " << *tmpit << " ";
    std::cout << std::endl;

    for (tmpit = pend.begin(); tmpit != pend.end(); tmpit++)
        std::cout << " main " << *tmpit << " ";
    std::cout << std::endl;
}

void PmergeMe::FordJohnson(std::string str)
{
    odd = true;
    parsfill(str);
    display();
    data = createPairsSorted();
    insertionSort(data);
    mainPend(data);

    display2();
}