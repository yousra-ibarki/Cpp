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
#include <ctime>
#include <deque>


//J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2*J(n-2)

class PmergeMe{
private:
    clock_t start;
    clock_t end;
    double totalTime;

    std::deque<int> dataD;
    std::deque<int>::iterator itD;

    std::vector<int> dataV;
    std::vector<int>::iterator itV;

    std::vector<std::pair<int, int> > tmpDataV;
    std::vector<std::pair<int, int> >::iterator tmpItV;

    std::deque<std::pair<int, int> > tmpDataD;
    std::deque<std::pair<int, int> >::iterator tmpItD;


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

    void displayV();
    void displayD();


    std::vector<std::pair<int, int> > createPairsSortedV();
    std::deque<std::pair<int, int> > createPairsSortedD();
    bool isnumber(std::string str);
    // void split();

    void insertionSortV(std::vector<std::pair<int, int> >& pairs);
    void insertionSortD(std::deque<std::pair<int, int> >& pairs);

    int jacobsthalNbr(int len);


    void mainPendV(std::vector<std::pair<int, int> >& data);
    void mainPendD(std::deque<std::pair<int, int> >& data);

    void binarySearch();
    void sortVector();
    void sortDeque();

};


#endif