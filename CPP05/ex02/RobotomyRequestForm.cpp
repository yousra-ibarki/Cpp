#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    this->gradeSign = 72;
    this->gradeExec = 45;
    this->sign = false;
    this->target = "Default Target";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
    this->gradeSign = 72;
    this->gradeExec = 45;
    this->sign = false;
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
{
    *this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this != &obj)
    {
        this->gradeSign = obj.gradeSign;
        this->gradeExec = obj.gradeExec;
        this->sign = obj.sign;
    }
    return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat& Bur) {
    if(Bur.getGrade() <= this->gradeSign){
        this->sign = true;
        std::cout << Bur.getName() << " Signed The Form " << this->target << " Succefully!" << std::endl;
    }
    else{
        std::cout << "Bureaucrat " << Bur.getName() << " couldn't sign the AForm" << this->target << " Because The Grade Is Too Low!" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeExec)
        throw GradeNotCompatibleExec();
    else
    {
        std::cout << "Makes some drilling noises..." << std::endl;
        std::cout << this->target << " Has Been Robotomized Successfully " << std::endl;
    }
}

const char *RobotomyRequestForm::GradeNotCompatibleSign::what() const throw()
{
    return "The Robotomy Failed To Sign The Form!";
}
const char *RobotomyRequestForm::GradeNotCompatibleExec::what() const throw()
{
    return "The Robotomy Failed To Execute The Form!";
}
