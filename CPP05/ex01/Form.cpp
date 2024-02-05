#include "Form.hpp"

Form::Form() :  gradeToSign(150), executedGrade(150), name("Form's name"){
    this->sign = false;
}

Form::~Form(){

}

Form::Form(const std::string name, int gradeToSign, int executedGrade):gradeToSign(gradeToSign), executedGrade(executedGrade),  name(name) {
    if(gradeToSign < 1 || executedGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(gradeToSign > 150 || executedGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form& obj): gradeToSign(obj.gradeToSign), executedGrade(obj.executedGrade), name(obj.name) {
    this->sign = obj.sign;
}

Form& Form::operator=(const Form& obj){
    if(this == &obj)
        return *this;
    return *this;
}

int Form::getGradeToSign() const{
    return this->gradeToSign;
}

int Form::getExecutedGrade() const{
    return this->executedGrade;
}
std::string Form::getName() const{
    return this->name;
}
bool Form::getSign() const
{
    return this->sign;
}

// void Form::beSigned(Bureaucrat& Bur){
//     if(Bur.getGrade() <= this->gradeToSign){
//         this->sign = true;
//         std::cout << "Bureaucrat " << Bur.getName() << " Signed The Form " << this->getName() << " Succefully!" << std::endl;
//     }
//     else{
//         std::cout << "Bureaucrat " << Bur.getName() << " couldn't sign the Form" << this->getName() << " Because The Grade Is Too Low!" << std::endl;
//         throw Bureaucrat::GradeTooLowException();
//     }

// }

const char* Form::GradeTooHighException::what() const throw(){
            return "Form's Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw(){
            return "Form's Grade Too Low";
}


