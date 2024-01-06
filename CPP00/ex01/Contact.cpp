#include "PhoneBook.hpp"

void Contact::ft_add_name(const std::string &new_name, const std::string &new_last, const std::string &new_nickname){
    first_name = new_name;
    last_name = new_last;
    nickname = new_nickname;
}

void Contact::ft_add_nbrPhone(const std::string &new_nbrPhone, const std::string &new_secret){
    nbr_phone = new_nbrPhone;
    dark_secret = new_secret;    
}

void Contact::ft_print() const{
    std::string copy;

    if(first_name.length() > 10){
        std::strncpy(copy, first_name, 9);
        copy[10] = '.';
        std::cout << std::setw(10) << copy << "|";
    }

    else{ 
        std::cout << std::setw(10) << first_name << "|";
        std::cout << std::setw(10) << last_name << "|";
        std::cout << std::setw(10) << nickname << "|";
        std::cout << std::endl;
    }
}
void Contact::ft_print_var() const{
        std::cout << "First Name:         " << first_name << std::endl;
        std::cout << "Last Name:          " << last_name << std::endl;
        std::cout << "Nickname:           " << nickname << std::endl;
        std::cout << "Phone Number:       " << nbr_phone << std::endl;
        std::cout << "The Darkest Secret: " << dark_secret << std::endl;
}