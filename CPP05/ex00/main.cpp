#include "Bureaucrat.hpp"
std::ostream &operator<<(std::ostream &os,Bureaucrat &obj)
{
    os << "Bureaucrat " << obj.getName() << " has a Grade " << obj.getGrade() << std::endl;
    return os;
}

int main()
{
    std::cout << "**********Incrementing Test**********" << std::endl << std::endl;
    Bureaucrat *Mehdi = new Bureaucrat("Mehdi", 2);
    try
    {
        std::cout << *Mehdi << std::endl;
        Mehdi->incrementGrade();
        std::cout << *Mehdi << std::endl;
        Mehdi->incrementGrade();
        std::cout << *Mehdi << std::endl;
        Mehdi->incrementGrade();
        std::cout << *Mehdi << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    delete Mehdi;

    std::cout << std::endl;
    std::cout << "**********Decrementing Test**********" << std::endl << std::endl;

    Bureaucrat *Latifa = new Bureaucrat("Latifa", 100);
    try
    {
        std::cout << *Latifa << std::endl;
        Latifa->decrementGrade(4);
        std::cout << *Latifa << std::endl;
        Latifa->decrementGrade(10);
        std::cout  << *Latifa << std::endl;
        Latifa->decrementGrade(4);
        std::cout << *Latifa << std::endl;
        Latifa->decrementGrade(150);
        std::cout << *Latifa << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    delete Latifa;

    std::cout << std::endl;

    std::cout << "**********Declaring Test**********" << std::endl << std::endl;
    try
    {
        Bureaucrat Sara("Sara", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat Sara("Sara", -2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
