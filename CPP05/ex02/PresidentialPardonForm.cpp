#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    this->sign = 25;
    this->exec = 5;
}

PresidentialPardonForm::~PresidentialPardonForm(){

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj){
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
    if(this != &obj){
        this->sign = obj.sign;
        this->exec = obj.exec;
    }
    return *this;
}

void PresidentialPardonForm::beSigned(Bureaucrat& obj){
    (void) obj;
}