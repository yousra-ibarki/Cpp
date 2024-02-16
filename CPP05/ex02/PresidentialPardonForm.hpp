#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
    int gradeSign;
    int gradeExec;
    std::string target;
    std::string president;
    bool sign;
public:
    class GradeNotCompatibleSign : public std::exception{
    public:
        const char* what() const throw();
    };
    class GradeNotCompatibleExec : public std::exception{
    public:
        const char* what() const throw();
    };
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& obj);

    void execute(const Bureaucrat& bure) const;

    void    beSigned(Bureaucrat& obj) ;
};

#endif