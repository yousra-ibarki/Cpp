#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

class Intern : public AForm{
public:
    Intern();
    ~Intern();
    Intern(const Intern& obj);
    Intern& operator=(const Intern& obj);

    void makeForm(std::string nameForm, std::string targetForm);
};

#endif