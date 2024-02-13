#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Name: " << obj.getName() << std::endl;
	os << "Grade To Sign: " << obj.getGradeToSign() << std::endl;
	os << "Grade To Execute: " << obj.getExecutedGrade() << std::endl;
	os << "Sign: " << obj.getSign() << std::endl;
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
		Bureaucrat Bob("Bob", 2);
		Form yo("Tax", 15, 2);
		std::cout << Bob << std::endl;
		std::cout << yo << std::endl;
		yo.beSigned(Bob);
		Bob.signForm(yo);
		std::cout << std::endl;
		std::cout << Bob << std::endl;
		std::cout << yo << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
