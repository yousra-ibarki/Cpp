#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat")
{
    this->grade = 15;
}
Bureaucrat::~Bureaucrat()
{

}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    // std::cout << "Bureaucrat Created" << std::endl;
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    *this = obj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if(this != &obj)
    {
        this->grade = obj.grade;
    }
    return *this;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}
std::string Bureaucrat::getName() const
{
    return this->name;
}

void Bureaucrat::incrementGrade()
{
    std::cout << "Grad incrementing by 1" << std::endl;
    if(this->grade - 1 < 1)
        throw GradeTooHighException();
    else if(this->grade - 1 > 150)
        throw GradeTooLowException();
    this->grade--;
}
void Bureaucrat::decrementGrade()
{
    std::cout << "Grad decrementing by 1" << std::endl;
    if(this->grade + 1 < 1)
        throw GradeTooHighException();
    else if(this->grade + 1 > 150)
        throw GradeTooLowException();
        this->grade++;
}

void Bureaucrat::incrementGrade(int amount){
    std::cout << "Grad incrementing by " << amount << std::endl;
    if(this->grade - amount < 1)
        throw GradeTooHighException();
    else if(this->grade - amount > 150)
        throw GradeTooLowException();
    this->grade -= amount;
}

void Bureaucrat::decrementGrade(int amount){
    std::cout << "Grad decrementing by " << amount << std::endl;
    if(this->grade + amount < 1)
        throw GradeTooHighException();
    else if(this->grade + amount > 150)
        throw GradeTooLowException();
    this->grade += amount;

}


const char* Bureaucrat::GradeTooHighException::what() const throw(){
            return "Bureaucrat's Grade Too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
            return "Bureaucrat's Grade Too Low!";
}

void Bureaucrat::signForm(AForm& formObj){
    formObj.beSigned(*this);
    (void) formObj;
}

void Bureaucrat::executeForm(AForm const &form){
    form.execute(*this);
}
