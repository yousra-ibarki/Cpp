#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
    int sign;
    int exec;
    std::string target;
    std::string president;
public:
    PresidentialPardonForm();
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& obj);
    void    beSigned(Bureaucrat& obj);
};

#endif