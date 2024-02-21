#include "easyfind.hpp"

int main(){
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(95);
    vec.push_back(57);
    vec.push_back(23);
    // for(int i = 0; i < size; i++){
    //     vec.push_back(i);
    // }
    // for(int j = 0; j < size;  j++)
    //     std::cout << j << std::endl;
    try{
        easyfind(vec, 10);

    }
    catch(unsigned long a){
        std::cout <<  a << " this occurrence did not found" << std::endl;
    }
}   