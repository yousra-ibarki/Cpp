#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
private:
    bool        sign;
    const int   gradeToSign;
    const int   executedGrade;
    const       std::string name;
public:
    class GradeTooHighException : public std::exception{
    public: 
       const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
    public:
        const char *what() const throw();
    };
    Form();
    Form(const std::string name, int gradeToSign, int executedGrade);
    virtual ~Form();
    Form(const Form& obj);
    Form& operator=(const Form& obj);
    int getGradeToSign() const;
    int getExecutedGrade() const;
    bool getSign() const;
    std::string getName() const;
    void beSigned(Bureaucrat& obj);

    virtual void checkToExecute(const Bureaucrat& bure) const = 0;

    


};

#endif