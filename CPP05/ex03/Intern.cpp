#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern Constructor Called" << std::endl;
}

Intern::~Intern(){
    std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(const Intern& obj){
    *this = obj;
}

Intern& Intern::operator=(const Intern& obj){
    if(this != &obj)
        *this = obj;
    return *this;
}

void Intern::makeForm(std::string nameForm, std::string targetForm){
    (void) nameForm;
    (void) targetForm;
    std::cout << "makeForm member Function" << std::endl;
}