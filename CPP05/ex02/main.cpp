#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

// std::ostream &operator<<(std::ostream &os,AForm &obj)
// {
//     os << "Name " << obj.getName() << std::endl;
//     os << "Grade To Sign " << obj.getGradeToSign() << std::endl;
//     os << "Grade To Execute " << obj.getExecutedGrade() << std::endl;
//     os << "Sign " << obj.getSign() << std::endl;
//     return os;
// }

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj)
{
    os << "Bureaucrat's Name " << obj.getName();
    os << " With Grade " << obj.getGrade() << std::endl;
    return os;
}



int main() {
	try{
		Bureaucrat yousra("yousra", 11);
		std::cout << yousra << std::endl;
		ShrubberyCreationForm form1("Abricot");
		
		yousra.incrementGrade(6);
		std::cout << yousra << std::endl;
		yousra.executeForm(form1);
		std::cout << std::endl;
		RobotomyRequestForm form2("Asmaa");
		yousra.executeForm(form2);
		std::cout << std::endl;
		PresidentialPardonForm form3("Merry");
		yousra.executeForm(form3);
		std::cout << std::endl;
	}
	catch(std::exception& ex){
		std::cout << ex.what()<< std::endl;
	}
	
}
