#ifndef ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
    int sign;
    int exec;
    std::string target;
    std::string robotName;
public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
    void    beSigned(Bureaucrat& obj);
};

#endif
