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

void ShrubberyCreationForm::beSigned(Bureaucrat &obj)
{
    (void)obj;
    std::cout << "beSigned member function" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    std::cout << "this grade " << this->gradeSign << " Bureaucrat's grade " << executor.getGrade() << std::endl;
    if (this->gradeSign == executor.getGrade())
    {
        std::cout << "it works" << std::endl;
        if (this->gradeExec == executor.getGrade())
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
            file.close();
        }
        else
            throw(executor.getGrade());
    }
    else
        throw(executor.getGrade());
}
