#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :  gradeToSign(150), executedGrade(150), name("AForm's name"){
    this->sign = false;
}

AForm::~AForm(){

}

AForm::AForm(const std::string name, int gradeToSign, int executedGrade):gradeToSign(gradeToSign), executedGrade(executedGrade),  name(name) {
    if(gradeToSign < 1 || executedGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(gradeToSign > 150 || executedGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& obj): gradeToSign(obj.gradeToSign), executedGrade(obj.executedGrade), name(obj.name) {
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
std::string AForm::getName() const{
    return this->name;
}
bool AForm::getSign() const
{
    return this->sign;
}

// void AForm::beSigned(Bureaucrat& Bur){
//     if(Bur.getGrade() <= this->gradeToSign){
//         this->sign = true;
//         std::cout << "Bureaucrat " << Bur.getName() << " Signed The AForm " << this->getName() << " Succefully!" << std::endl;
//     }
//     else{
//         std::cout << "Bureaucrat " << Bur.getName() << " couldn't sign the AForm" << this->getName() << " Because The Grade Is Too Low!" << std::endl;
//         throw Bureaucrat::GradeTooLowException();
//     }
// }

const char* AForm::GradeTooHighException::what() const throw(){
            return "AForm's Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw(){
            return "AForm's Grade Too Low";
}


