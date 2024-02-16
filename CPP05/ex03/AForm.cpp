#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm() :  gradeToSign(150), executedGrade(150), name("Default"), target("NonTarget"){
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

const std::string& AForm::getTarget() const {
	return this->target;
}


const char* AForm::GradeTooHighException::what() const throw(){
            return "AForm's Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw(){
            return "AForm's Grade Too Low";
}



