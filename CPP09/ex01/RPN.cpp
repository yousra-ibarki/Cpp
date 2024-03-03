#include "RPN.hpp"

RPN::RPN(){

}

RPN::RPN(const RPN& obj){
    *this = obj;
}

RPN::~RPN(){
}

RPN& RPN::operator=(const RPN& obj){
    (void)obj;
    return *this;
}

// void RPN::ft_RPN(char **str){

// }

void RPN::parsFill(char **str){
    for(int i = 1; str[i]; i++)
    {
            std::cout << "string = " << str[i] << std::endl;
    }
}