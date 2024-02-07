#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
private:
    bool        sign;
    const int   gradeToSign;
    const int   executedGrade;
    const       std::string name;
    const       std::string target;
public:
    class GradeTooHighException : public std::exception{
    public: 
       const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
    public:
        const char *what() const throw();
    };

    AForm();
    AForm(const std::string name, const std::string target,int gradeToSign, int executedGrade);
    virtual ~AForm();
    AForm(const AForm& obj);
    AForm&          operator=(const AForm& obj);
    int             getGradeToSign() const;
    int             getExecutedGrade() const;
    bool            getSign() const;
    const std::string&  getName() const;
    const std::string&  getTarget() const;

    // virtual void execute(Bureaucrat const& executor) const = 0;
    virtual void checkToExecute(Bureaucrat const& executor) const = 0;

    void    beSigned(Bureaucrat& Bur);
};

#endif
