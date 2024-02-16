#ifndef ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
    int gradeSign;
    int gradeExec;
    bool sign;
    std::string target;
    std::string robotName;
public:
    class GradeNotCompatibleSign : public std::exception{
    public:
        const char* what() const throw();
    };
    class GradeNotCompatibleExec : public std::exception{
    public:
        const char* what() const throw();
    };
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
    void    beSigned(Bureaucrat& Bur) ;
    void    execute(Bureaucrat const &executor) const;

};

#endif
