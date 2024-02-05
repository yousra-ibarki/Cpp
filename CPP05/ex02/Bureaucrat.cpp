#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat")
{
    std::cout << "Default Bureaucrat Created" << std::endl;
    this->grade = 15;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destroyed" << std::endl;

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

void AForm::beSigned(Bureaucrat& Bur){
    if(Bur.getGrade() <= this->gradeToSign){
        this->sign = true;
        std::cout << "Bureaucrat " << Bur.getName() << " Signed The AForm " << this->getName() << " Succefully!" << std::endl;
    }
    else{
        std::cout << "Bureaucrat " << Bur.getName() << " couldn't sign the AForm" << this->getName() << " Because The Grade Is Too Low!" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}


void Bureaucrat::signForm(AForm& formObj){
    //formObj.beSigned(*this);
    (void) formObj;
}