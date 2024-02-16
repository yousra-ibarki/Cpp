#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm{
private:
    int gradeSign;
    int gradeExec;
    bool sign;
    std::string target;
public:
     class GradeNotCompatibleSign : public std::exception{
    public:
        const char* what() const throw();
    };
    class GradeNotCompatibleExec : public std::exception{
    public:
        const char* what() const throw();
    };

    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

    void execute(const Bureaucrat& bure) const;
    void    beSigned(Bureaucrat& Bur) ;

};

#endif