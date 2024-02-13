#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    this->gradeSign = 145;
    this->gradeExec = 137;
    this->target = "Default Target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->gradeSign = 145;
    this->gradeExec = 137;
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
    }
    return *this;
}

void ShrubberyCreationForm::checkToExecute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeSign)
        throw GradeNotCompatibleSign();
    else
        std::cout << "The File Has Been Signed by " << executor.getName() <<" Successfully!" << std::endl;
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
        std::cout << "The File Has Been Created Successfully!" << std::endl;
        file.close();
    }
}

const char* ShrubberyCreationForm::GradeNotCompatibleSign::what() const throw(){
    return "The Grade is not compatible To Sign!";
}
const char* ShrubberyCreationForm::GradeNotCompatibleExec::what() const throw(){
    return "The Grade is not compatible To Execute!";
}

