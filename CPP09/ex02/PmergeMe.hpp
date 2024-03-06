#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>

//J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2*J(n-2)

class PmergeMe{
private:
    std::vector<int> dataV;
    std::vector<std::pair<int, int> > data;
    std::vector<std::pair<int, int> >::iterator it;


    std::vector<int>::iterator itV;
    std::string tokenV;

    int lastValue;
   
    bool odd; 
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& obj);
    PmergeMe(const PmergeMe& obj);

    void FordJohnson(std::string str);

    void parsfill(std::string &input);

    void display();
    void display2();


    std::vector<std::pair<int, int> > createPairsSorted();
    bool isnumber(std::string str);
    // void split();

    void insertionSort(std::vector<std::pair<int, int> >& pairs);

    int jacobsthalNbr(int len);


    void mainPend(std::vector<std::pair<int, int> >& data);

    void binarySearch();
};


#endif