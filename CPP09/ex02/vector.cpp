#include "PmergeMe.hpp"

std::vector<std::pair<int, int> > PmergeMe::createPairsSortedV()
{
    int tmp;
    std::pair<int, int> pairV;
    if (dataV.size() % 2 == 0)
        odd = false;
    if (odd == true)
    {
        this->lastValue = dataV.back();
        dataV.pop_back();
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
        tmpDataV.push_back(pairV);
        itV++;
    }
    return tmpDataV;
}

void PmergeMe::insertionSortV(std::vector<std::pair<int, int> > &pairs)
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

void PmergeMe::mainPendV(std::vector<std::pair<int, int> > &tmpDataV)
{
    std::vector<int> mainV;
    std::vector<int>::iterator pendItV;
    std::vector<int>::iterator mainItV;

    std::vector<int> pendV;

    int j = 0;
    for (tmpItV = tmpDataV.begin(); tmpItV != tmpDataV.end(); tmpItV++)
    {
        pendV.push_back(tmpItV->first);
        mainV.push_back(tmpItV->second);
        j++;
    }

    mainV.insert(mainV.begin(), pendV[0]);
    pendV.erase(pendV.begin());
    for (pendItV = pendV.begin(); pendItV != pendV.end(); pendItV++)
    {
        mainItV = std::lower_bound(mainV.begin(), mainV.end(), *pendItV);
        mainV.insert(mainItV, *pendItV);
    }
    if (odd == true)
    {
        mainItV = std::lower_bound(mainV.begin(), mainV.end(), lastValue);
        mainV.insert(mainItV, lastValue);
    }
    pendV.clear();
    dataV = mainV;
}

void PmergeMe::sortVector(){
    std::cout << "before: ";
    displayV();
    start = std::clock();

    tmpDataV = createPairsSortedV();
    insertionSortV(tmpDataV);
    mainPendV(tmpDataV);

    end = std::clock();
    totalTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "after:  ";
    displayV();
    std::cout << "Time to process a range of " << dataV.size() << " elements with std::vector : " << (totalTime * 1000000) << " microseconds" << std::endl;
}