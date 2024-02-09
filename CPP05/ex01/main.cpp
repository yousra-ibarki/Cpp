#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Name " << obj.getName() << std::endl;
	os << "Grade To Sign " << obj.getGradeToSign() << std::endl;
	os << "Grade To Execute " << obj.getExecutedGrade() << std::endl;
	os << "Sign " << obj.getSign() << std::endl;
	return os;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << "Bureaucrat " << obj.getName() << " has a Grade " << obj.getGrade() << std::endl;
	return os;
}

int main()
{
	try
	{
		
		Bureaucrat Mehdi("Mehdi", 2);
		Form yo("Tax", 50, 2);
		std::cout << Mehdi << std::endl;
		Mehdi.incrementGrade();
		std::cout << Mehdi << std::endl;
		Mehdi.decrementGrade();
		std::cout << Mehdi << std::endl;
		Mehdi.decrementGrade(10);
		std::cout << Mehdi << std::endl;
		Mehdi.incrementGrade(10);
		std::cout << Mehdi << std::endl;

		Mehdi.signForm(yo);
		std::cout << std::endl;
		
		Mehdi.incrementGrade(150);
		std::cout << Mehdi << std::endl;

		yo.beSigned(Mehdi);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
