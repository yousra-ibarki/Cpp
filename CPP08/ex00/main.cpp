#include "easyfind.hpp"

int main(){
    std::vector<int> vec;
    int size  = 15;
    for(int i = 0; i < size; i++){
        vec.push_back(i);
    }
    for(int j = 0; j < size;  j++)
        std::cout << j << std::endl;
    easyfind(vec, 5)
}   