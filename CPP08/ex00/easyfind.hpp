#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include "algorithm"

template <typename T>

void easyfind(const T &vec, unsigned long nbr){
    std::cout << vec.size() << std::endl;

    std::vector<const int* >::iterator out = std::find(vec.begin(), vec.end() , nbr);

    if(out != vec.end())
        std::cout << "the element " << nbr << " found at index " << std::endl;
    else
        throw(nbr);
}

#endif
