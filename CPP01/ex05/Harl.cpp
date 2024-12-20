#include "Harl.hpp"

void Harl::debug(void){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}
void Harl::info(void){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years where as you started working here since last month." << std::endl;
}
void Harl::error(void){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
Harl::Harl(){
    strcpy(arr[0], "debug");
    strcpy(arr[1], "info");
    strcpy(arr[2], "warning");
    strcpy(arr[3], "error");

    arrr[0] = &Harl::debug;;
    arrr[1] = &Harl::info;;
    arrr[2] = &Harl::warning;
    arrr[3] = &Harl::error;;
}

void Harl::complain(std::string level){
    FPtr called;
    for (int i = 0; i < 4; i++)
    {
        if (level == arr[i])
        {
            called = arrr[i];
            (this->*called)();
            exit(0);
        }
    }
    std::cout << "Invalid Input" << std::endl;
}
