#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << "Bureaucrat " << obj.getName() << " has a Grade " << obj.getGrade() << std::endl;
    return os;
}

int main()
{
    try{
        Bureaucrat Bob("Bob", 149+10);
        std::cout << Bob << std::endl;
        Bob.incrementGrade();
        std::cout << Bob << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat franc("franc", -1);
        std::cout << franc << std::endl;
        franc.decrementGrade();
        std::cout << franc << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat B("Valid", 45);
        std::cout << B << std::endl;
        B.decrementGrade(10);
        std::cout << B << std::endl;
        B.incrementGrade(10);
        std::cout << B << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
