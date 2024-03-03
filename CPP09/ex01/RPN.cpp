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

// std::string &RPN::split(){
//     std::istringstream iss(this->input);

//     std::getline(iss, this->token, ' ');
//     std::cout << token << " this is token" << std::endl;
//     return token;
// }

void RPN::parsFill(char *str){
  
}

void RPN::display() {
   
}


std::istringstream string("1 2 3 4 5 6 7 8 9* - +  + + + + + +");
std::string token;


while(string >> token) == 1
{
    if (isdegit(toke))
        push
        else if (...)
        if(token == +)
            data.push(second)
}