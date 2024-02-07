#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    this->gradeSign = 25;
    this->gradeExec = 5;
    this->target = "Default Target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    this->gradeSign = 25;
    this->gradeExec = 5;
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
    }
    return *this;
}

void PresidentialPardonForm::beSigned(Bureaucrat& obj){
    (void) obj;
}

void PresidentialPardonForm::checkToExecute(Bureaucrat const &executor) const
{
    // std::cout << "this grade " << this->gradeSign << " Bureaucrat's grade " << executor.getGrade() << std::endl;
    if (executor.getGrade() > this->gradeSign)
        throw GradeNotCompatibleSign();
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