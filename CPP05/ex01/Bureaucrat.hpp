#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat{
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighException : public std::exception{
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
    public:
        const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);
    std::string getName();
    int getGrade();
    void incrementGrade();
    void decrementGrade();
    void incrementGrade(int amount);
    void decrementGrade(int amount);
    void signForm(Form& formObj);
    
};

#endif