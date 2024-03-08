#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

void easyfind(T &vec, int nbr){

    typename T::iterator out = std::find(vec.begin(), vec.end() , nbr);

    if(out != vec.end())
        std::cout << "the element " << nbr << " found at index "<< std::distance(vec.begin(), out) << std::endl;
    else
        throw(nbr);
}

#endif
