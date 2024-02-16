#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    this->gradeSign = 25;
    this->gradeExec = 5;
    this->sign = false;
    this->target = "Default Target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    this->gradeSign = 25;
    this->gradeExec = 5;
    this->sign = false;
    this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj){
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
    if(this != &obj){
        this->gradeSign = obj.gradeSign;
        this->gradeExec = obj.gradeExec;
        this->sign = obj.sign;
    }
    return *this;
}

void PresidentialPardonForm::beSigned(Bureaucrat& Bur) {
    if(Bur.getGrade() <= this->gradeSign){
        this->sign = true;
        std::cout << Bur.getName() << " Signed The Form " << this->target << " Succefully!" << std::endl;
    }
    else{
        std::cout << "Bureaucrat " << Bur.getName() << " couldn't sign the AForm" << this->target << " Because The Grade Is Too Low!" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeExec)
        throw GradeNotCompatibleExec();
    else
    {
        std::cout << this->target << " Has Been Pardoned By Zaphod Beeblebrox Successfully!" << std::endl;
    }
}

const char* PresidentialPardonForm::GradeNotCompatibleSign::what() const throw(){
    return "The Robotomy Failed To Sign The Form!";
}
const char* PresidentialPardonForm::GradeNotCompatibleExec::what() const throw(){
    return "The Robotomy Failed To Execute The Form!";
}