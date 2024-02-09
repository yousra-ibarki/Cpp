#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

// int main() {
// 	try{
// 		Bureaucrat yousra("yousra", 11);
// 		std::cout << yousra << std::endl;
// 		ShrubberyCreationForm form1("Abricot");
		
// 		yousra.incrementGrade(6);
// 		std::cout << yousra << std::endl;
// 		yousra.executeForm(form1);
// 		std::cout << std::endl;
// 		RobotomyRequestForm form2("Asmaa");
// 		yousra.executeForm(form2);
// 		std::cout << std::endl;
// 		PresidentialPardonForm form3("Merry");
// 		yousra.executeForm(form3);
// 		std::cout << std::endl;
// 	}
// 	catch(std::exception& ex){
// 		std::cout << ex.what()<< std::endl;
// 	}
	
// }


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
		ShrubberyCreationForm tree("Abricot");
		RobotomyRequestForm robot("Pan");
		PresidentialPardonForm pardon("Yousra");
		std::cout << Mehdi << std::endl;
		Mehdi.incrementGrade();
		std::cout << Mehdi << std::endl;
		Mehdi.decrementGrade();
		std::cout << Mehdi << std::endl;
		Mehdi.decrementGrade(10);
		std::cout << Mehdi << std::endl;
		Mehdi.incrementGrade(10);
		std::cout << Mehdi << std::endl;
		std::cout << std::endl;
		tree.checkToExecute(Mehdi);
		std::cout << std::endl;
		robot.checkToExecute(Mehdi);
		std::cout << std::endl;
		pardon.checkToExecute(Mehdi);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}

