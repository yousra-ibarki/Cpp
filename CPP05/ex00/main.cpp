#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << "Bureaucrat " << obj.getName() << " has a Grade " << obj.getGrade() << std::endl;
    return os;
}

int main()
{
    try
    {
        Bureaucrat Mehdi("NULL", 149+10);
        std::cout << Mehdi << std::endl;
        Mehdi.incrementGrade();
        std::cout << Mehdi << std::endl;
        Mehdi.decrementGrade();
        std::cout << Mehdi << std::endl;
        Mehdi.decrementGrade(10);
        std::cout << Mehdi << std::endl;
        Mehdi.incrementGrade(10);
        std::cout << Mehdi << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
