#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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
    os << "Bureaucrat's Name " << obj.getName() << std::endl;
    os << "Bureaucrat's Grade " << obj.getGrade() << std::endl;
    return os;
}



int main() {
	Bureaucrat yousra("yousra", 145);
	ShrubberyCreationForm form1("Abricot");
	std::cout << yousra << std::endl;
	try{
		yousra.incrementGrade(8);
		std::cout << yousra << std::endl;
	}
	catch(std::exception& ex){
		std::cout << ex.what()<< std::endl;
	}
	// form1.execute(yousra);
	std::cout << std::endl;
	
}
