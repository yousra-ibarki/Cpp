#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

class Intern{
private:
    typedef struct s_form{
        AForm *form;
        std::string name;
    }t_form;
public:
    Intern();
    ~Intern();
    Intern(const Intern& obj);
    Intern& operator=(const Intern& obj);
    
    AForm* makeForm(std::string nameForm, std::string targetForm);
};

#endif