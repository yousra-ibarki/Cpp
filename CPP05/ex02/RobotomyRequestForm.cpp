#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
    this->sign = 72;
    this->exec = 45;
}

RobotomyRequestForm::~RobotomyRequestForm(){

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj){
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
    if(this != &obj){
        this->sign = obj.sign;
        this->exec = obj.exec;
    }
    return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat& obj){
    (void)obj;
}
