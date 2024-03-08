#include "easyfind.hpp"

int main(){
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(95);
    vec.push_back(57);
    vec.push_back(23);
    int size = 100;

    for(int i = 0; i < size; i++){
        vec.push_back(i);
    }

    try{
        easyfind(vec, 145);

    }
    catch(int a){
        std::cout << "couldn't find " << a << std::endl;
    }
}   