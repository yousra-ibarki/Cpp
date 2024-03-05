#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <sstream>


class PmergeMe{
private:
    std::vector<int> dataV;
    std::vector<int>::iterator itV;
    std::string tokenV;
    // unsigned int nbr;
    bool odd; 
    int lastValue;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& obj);
    PmergeMe(const PmergeMe& obj);

    void FordJohnson(std::string str);

    void parsfill(std::string &input);

    void display();

    bool isnumber(std::string str);
    // void split();
};


#endif