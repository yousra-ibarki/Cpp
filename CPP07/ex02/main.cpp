#include "Array.hpp"

int main(){

    try{
    Array<int> obj(5);
    
    }
    catch(std::exception &e){
        std::cout << "exception catched" << std::endl;
        std::cout << e.what() << std::endl;
    }
}