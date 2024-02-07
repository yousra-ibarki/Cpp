#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
    this->gradeSign = 72;
    this->gradeExec = 45;
    this->target = "Default Target";
}

RobotomyRequestForm::~RobotomyRequestForm(){

}

RobotomyRequestForm::RobotomyRequestForm(std::string target){
    this->gradeSign = 72;
    this->gradeExec = 45;
    this->target = target;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj){
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
    if(this != &obj){
        this->gradeSign = obj.gradeSign;
        this->gradeExec = obj.gradeExec;
    }
    return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat& obj){
    (void)obj;
}

void RobotomyRequestForm::checkToExecute(Bureaucrat const &executor) const
{
    // std::cout << "this grade " << this->gradeSign << " Bureaucrat's grade " << executor.getGrade() << std::endl;
    if (executor.getGrade() > this->gradeSign)
        throw GradeNotCompatibleSign();
    if (executor.getGrade() > this->gradeExec)
        throw GradeNotCompatibleExec();
    else
    {
        std::cout << "NOISE KHKHKHKHKH" << std::endl;
        std::cout << this->target << " Has Been Robotomized Successfully " << std::endl;
    }
}


const char* RobotomyRequestForm::GradeNotCompatibleSign::what() const throw(){
    return "The Robotomy Failed To Sign The Form!";
}
const char* RobotomyRequestForm::GradeNotCompatibleExec::what() const throw(){
    return "The Robotomy Failed To Execute The Form!";
}
