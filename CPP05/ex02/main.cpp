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
		std::cout << "∞∞∞∞∞∞∞∞ShrubberyCreationForm∞∞∞∞∞∞∞∞" << std::endl;
		Bureaucrat Bob("Bob", 14);
		ShrubberyCreationForm tree("Abricot");
		std::cout << Bob << std::endl;
		tree.checkToExecute(Bob);
		std::cout << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "∞∞∞∞∞∞∞∞RobotomyRequestForm∞∞∞∞∞∞∞∞" << std::endl;
		Bureaucrat Jean("Jean", 5);
		RobotomyRequestForm robot("Electricity");
		std::cout << Jean << std::endl;
		robot.checkToExecute(Jean);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "∞∞∞∞∞∞∞∞PresidentialPardonForm∞∞∞∞∞∞∞∞" << std::endl;
		Bureaucrat Franc("Franc", 15);
		PresidentialPardonForm pardon("Tax");
		std::cout << Franc << std::endl;
		pardon.checkToExecute(Franc);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}

// int main() {
// 	{
// 		AForm *f = new PresidentialPardonForm("ouahidi");
// 		Bureaucrat	b("noureddine", 5);
// 		try
// 		{
// 			f->beSigned(b);
// 			f->checkToExecute(b);
// 		}
// 		catch(std::exception &e){
// 			std::cerr << "Error: " <<"\033[31m"<< e.what()<<"\033[0m"<<std::endl;;
// 		}
// 		delete f;
// 	}
// 	std::cout<<"<<==========================================>>\n";
// 	{
// 		AForm *f = new ShrubberyCreationForm("ouahidi");
// 		Bureaucrat	b("noureddine", 14);
// 		try
// 		{
// 			f->beSigned(b);
// 			f->checkToExecute(b);
// 		}
// 		catch(std::exception &e){
// 			std::cerr << "Error: " <<"\033[31m"<< e.what()<<"\033[0m"<<std::endl;;
// 		}
// 		delete f;

// 	}
// 	std::cout<<"<<==========================================>>\n";
// 	{
// 		AForm *f = new RobotomyRequestForm("ouahidi");
// 		Bureaucrat	b("noureddine", 45);
// 		try
// 		{
// 			f->beSigned(b);
// 			f->checkToExecute(b);
// 		}
// 		catch(std::exception &e){
// 			std::cerr << "Error: " <<"\033[31m"<< e.what()<<"\033[0m"<<std::endl;;
// 		}
// 		delete f;
// 	}
// 	return 0;
// }