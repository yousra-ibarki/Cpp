#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

// class AForm;
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

    void incrementGrade();
    void decrementGrade();
    void incrementGrade(int amount);
    void decrementGrade(int amount);

    void executeForm(AForm const &form);
    
    std::string getName() const;
    int getGrade() const;

    void signForm(AForm& formObj);
    
};

#endif