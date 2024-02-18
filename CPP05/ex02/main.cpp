#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << "Bureaucrat " << obj.getName() << " has a Grade " << obj.getGrade() << std::endl;
	return os;
}

int main()
{
	try{
		std::cout << "∞∞∞∞∞∞∞∞ShrubberyCreationForm∞∞∞∞∞∞∞∞" << std::endl << std::endl;
		Bureaucrat Bob("Bob", 14);
		ShrubberyCreationForm *tree = new ShrubberyCreationForm("Abricot");
		std::cout << std::endl;
		Bob.signForm(*tree);
		std::cout << std::endl;
		Bob.executeForm(*tree);
		std::cout << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "∞∞∞∞∞∞∞∞RobotomyRequestForm∞∞∞∞∞∞∞∞" << std::endl << std::endl;
		Bureaucrat Jean("Jean", 123);
		RobotomyRequestForm *robot = new RobotomyRequestForm("Electricity");
		std::cout << std::endl;
		Jean.signForm(*robot);
		std::cout << std::endl;
		Jean.executeForm(*robot);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "∞∞∞∞∞∞∞∞PresidentialPardonForm∞∞∞∞∞∞∞∞" << std::endl << std::endl;
		Bureaucrat Franc("Franc", 15);
		PresidentialPardonForm *pardon = new PresidentialPardonForm("Tax");
		std::cout << std::endl;
		Franc.signForm(*pardon);
		std::cout << std::endl;
		Franc.executeForm(*pardon);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
