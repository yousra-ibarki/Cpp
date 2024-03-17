#include "PmergeMe.hpp"


std::deque<std::pair<int, int> > PmergeMe::createPairsSortedD()
{
    int tmp;
    std::pair<int, int> pairD;
    if (dataD.size() % 2 == 0)
        odd = false;
    if (odd == true)
    {
        this->lastValue = dataD.back();
        dataD.pop_back();
    }

    for (itD = dataD.begin(); itD != dataD.end(); itD++)
    {
        itD++;
        tmp = *itD;
        itD--;
        pairD = std::make_pair(*itD, tmp);
        if (pairD.first > pairD.second)
        {
            std::swap(pairD.first, pairD.second);
            // tmp = pairD.first;
            // pairD.first = pairD.second;
            // pairD.second = tmp;
        }
        tmpDataD.push_back(pairD);
        itD++;
    }
    return tmpDataD;
}

void PmergeMe::insertionSortD(std::deque<std::pair<int, int> > &pairs)
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



void PmergeMe::mainPendD(std::deque<std::pair<int, int> > &tmpDataD)
{
    std::deque<int> mainD;
    std::deque<int> pendD;
    std::deque<int>::iterator pendItD;
    std::deque<int>::iterator mainItD;

   
    int j = 0;
    for (tmpItD = tmpDataD.begin(); tmpItD != tmpDataD.end(); tmpItD++)
    {
        pendD.push_back(tmpItD->first);
        mainD.push_back(tmpItD->second);
        j++;
    }

    mainD.insert(mainD.begin(), pendD[0]);
    pendD.erase(pendD.begin());
    for (pendItD = pendD.begin(); pendItD != pendD.end(); pendItD++)
    {
        mainItD = std::lower_bound(mainD.begin(), mainD.end(), *pendItD);
        mainD.insert(mainItD, *pendItD);
    }
    if (odd == true)
    {
        mainItD = std::lower_bound(mainD.begin(), mainD.end(), lastValue);
        mainD.insert(mainItD, lastValue);
    }
    pendD.clear();
    dataD = mainD;
    mainD.clear();
}

void PmergeMe::sortDeque()
{
    std::cout << "before: ";
    displayD();
    start = std::clock();
    tmpDataD = createPairsSortedD();
  
    insertionSortD(tmpDataD);
    mainPendD(tmpDataD);

    end = std::clock();
    totalTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "after:  ";
    displayD();
    std::cout << "Time to process a range of " << dataD.size() << " elements with std::deque : " << (totalTime * 1000000) << " microseconds" << std::endl;
}