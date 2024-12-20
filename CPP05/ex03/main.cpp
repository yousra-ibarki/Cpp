#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << "Bureaucrat " << obj.getName() << " has a Grade " << obj.getGrade() << std::endl;
	return os;
}

int main()
{
	try
	{
		Bureaucrat Bob("Bob", 1);
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		Bob.signForm(*rrf);
		Bob.executeForm(*rrf);


	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
