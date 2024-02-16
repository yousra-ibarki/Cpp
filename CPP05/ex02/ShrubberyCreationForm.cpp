#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    this->gradeSign = 145;
    this->gradeExec = 137;
    this->sign = false;
    this->target = "Default Target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->gradeSign = 145;
    this->gradeExec = 137;
    this->sign = false;
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
    *this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
        this->gradeSign = obj.gradeSign;
        this->gradeExec = obj.gradeExec;
        this->sign = obj.sign;
    }
    return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat& Bur) {
    if(Bur.getGrade() <= this->gradeSign){
        this->sign = true;
        std::cout << Bur.getName() << " Signed The Form " << this->target << " Succefully!" << std::endl;
    }
    else{
        std::cout << "Bureaucrat " << Bur.getName() << " couldn't sign the AForm" << this->target << " Because The Grade Is Too Low!" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeExec)
        throw GradeNotCompatibleExec();
    else
    {
        std::ofstream file(target + "_shrubbery");
        if (file.is_open())
        {
            file << "         ; ; ;                               " << std::endl;
            file << "       ;        ;  ;     ;;    ;             " << std::endl;
            file << "    ;                 ;         ;  ;         " << std::endl;
            file << "                    ;                        " << std::endl;
            file << "                   ;                ;;       " << std::endl;
            file << "   ;          ;            ;              ;  " << std::endl;
            file << "   ;            ';,        ;               ; " << std::endl;
            file << "   ;              'b      *                  " << std::endl;
            file << "    ;              '$    ;;                ;;" << std::endl;
            file << "   ;    ;           $:   ;:               ;  " << std::endl;
            file << " ;;      ;  ;;      *;  @@:        ;   ; ;   " << std::endl;
            file << "              ;     :@,@@:   ,;**:'   ;      " << std::endl;
            file << "  ;      ;,         :@@*: ;;**'      ;   ;   " << std::endl;
            file << "           ';o;    ;:@@';@*@'  ;             " << std::endl;
            file << "   ;  ;       'bq,;;:,@@*'   ,*      ;  ;    " << std::endl;
            file << "              ,p$q8,:@@'  ;p*'      ;        " << std::endl;
            file << "       ;     '  ; '@@Pp@@*'    ;  ;          " << std::endl;
            file << "        ;  ; ;;    Y7'.'     ;  ;            " << std::endl;
            file << "                  :@@:.                      " << std::endl;
            file << "                 .:@:'.                      " << std::endl;
            file << "               .::@@:.                       " << std::endl;
        }
        std::cout <<  this->target << " Has Been Created Successfully!" << std::endl;
        file.close();
    }
}

const char* ShrubberyCreationForm::GradeNotCompatibleSign::what() const throw(){
    return "The Grade is not compatible To Sign!";
}
const char* ShrubberyCreationForm::GradeNotCompatibleExec::what() const throw(){
    return "The Grade is not compatible To Execute!";
}

