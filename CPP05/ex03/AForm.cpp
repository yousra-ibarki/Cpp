#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm() :  gradeToSign(150), executedGrade(150), name("Default"), target("NonTarget"){
    this->sign = false;
}

AForm::~AForm(){
}

AForm::AForm(const std::string name, const std::string target,int gradeToSign, int executedGrade):gradeToSign(gradeToSign), executedGrade(executedGrade),  name(name), target(target) {
    if(gradeToSign < 1 || executedGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(gradeToSign > 150 || executedGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& obj): gradeToSign(obj.gradeToSign), executedGrade(obj.executedGrade), name(obj.name), target(obj.target) {
    this->sign = obj.sign;
}

AForm& AForm::operator=(const AForm& obj){
    if(this == &obj)
        return *this;
    return *this;
}

int AForm::getGradeToSign() const{
    return this->gradeToSign;
}

int AForm::getExecutedGrade() const{
    return this->executedGrade;
}
const std::string& AForm::getName() const{
    return this->name;
}
bool AForm::getSign() const
{
    return this->sign;
}

const std::string& AForm::getTarget() const {
	return this->target;
}

void AForm::beSigned(Bureaucrat& Bur){
    if(Bur.getGrade() <= this->gradeToSign){
        this->sign = true;
        std::cout << Bur.getName() << " Signed The Form " << this->getName() << " Succefully!" << std::endl;
    }
    else{
        std::cout << "Bureaucrat " << Bur.getName() << " couldn't sign the AForm" << this->getName() << " Because The Grade Is Too Low!" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw(){
            return "AForm's Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw(){
            return "AForm's Grade Too Low";
}



