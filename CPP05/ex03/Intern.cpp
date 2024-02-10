#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Constructor Called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    *this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
    if (this != &obj)
        *this = obj;
    return *this;
}

AForm *Intern::makeForm(std::string nameForm, std::string targetForm)
{
    t_form form[3];
    Bureaucrat a;
    this->objForm = NULL;

    form[0].name = "ShrubberyCreationForm";
    form[0].form = new ShrubberyCreationForm(targetForm);

    form[1].name = "RobotomyRequestForm";
    form[1].form = new RobotomyRequestForm(targetForm);

    form[2].name = "PresidentialPardonForm";
    form[2].form = new PresidentialPardonForm(targetForm);
    for (int i = 0; i < 3; i++)
    {
        if (form[i].name == nameForm)
        {
            objForm = form[i].form;
            // objForm->checkToExecute(a.clone());
        }
        else
            delete form[i].form;
    }
    if (objForm != NULL)
        std::cout << "Intern creates " << nameForm << std::endl;
    else
        std::cout << "usage: <Forms: |ShrubberyCreationForm\t|RobotomyRequestForm\t|PresidentialPardonForm|>" << std::endl;
    return objForm;
}