#include <iostream>
#include <string>


class Harl{
private:
char arr[4][8];
    void debug(void){
        std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    }
    void info(void){
        std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    }
    void warning(void){
        std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years where as you started working here since last month." << std::endl;
    }
    void error(void){
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    }
public:
    typedef void (Harl::*FPtr)();
    FPtr f1;
    FPtr f2;
    FPtr f3;
    FPtr f4;
    FPtr arrr[4];

    Harl(){
        
        strcpy(arr[0], "debug");
        strcpy(arr[1], "info");
        strcpy(arr[2], "warning");
        strcpy(arr[3], "error");

        f1 = &Harl::debug;
        f2 = &Harl::info;
        f3 = &Harl::warning;
        f4 = &Harl::error;
        arrr[0] = f1;
        arrr[1] = f2;
        arrr[2] = f3;
        arrr[3] = f4;
    }
    void complain(std::string level){
    FPtr called;
    for(int i = 0; i < 4; i++){
        if(level == arr[i]){
            called = arrr[i];
            (this->*called)();
            exit(0);
        }
    }
        std::cout << "Invalid Input" << std::endl;
    }

};

int main(int ac, char **av)
{
    if(ac == 2)
    {
        Harl obj;
        obj.complain(av[1]);   
    }
    else
        std::cout << "Usage: <level: debug/info/warning/error>" << std::endl;
}
