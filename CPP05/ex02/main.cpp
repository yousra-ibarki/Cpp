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
    os << "Bureaucrat's Name " << obj.getName();
    os << " With Grade " << obj.getGrade() << std::endl;
    return os;
}



int main() {
	try{
		Bureaucrat yousra("yousra", 150);
		std::cout << yousra << std::endl;
		ShrubberyCreationForm form1("Abricot");
		yousra.incrementGrade(5);
		std::cout << yousra << std::endl;
		form1.execute(yousra);
	}
	catch(std::exception& ex){
		std::cout << ex.what()<< std::endl;
	}
	// try{
	// 	Bureaucrat yousra("yousra", 150);
	// 	std::cout << yousra << std::endl;
	// 	AForm *obj = new ShrubberyCreationForm("Abricot");
	// 	obj->execute(yousra);
	// }
	// catch(std::exception& ex){
	// 	std::cout << ex.what()<< std::endl;
	// }
		// delete obj;
	std::cout << std::endl;
	
}
