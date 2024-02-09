#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& obj);

    void incrementGrade();
    void decrementGrade();
    void incrementGrade(int amount);
    void decrementGrade(int amount);

    std::string getName() const;
    int getGrade() const;


    
};
    std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif