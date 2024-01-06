#include "PhoneBook.hpp"
#include "Contact.hpp"


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
    std::cout << std::setw(10) << ((first_name.length() > 10) ? (first_name.substr(0, 9) + ".") : first_name) << "|";  
    std::cout << std::setw(10) << ((last_name.length() > 10) ? (last_name.substr(0, 9) + ".") : last_name) << "|";  
    std::cout << std::setw(10) << ((nickname.length() > 10) ? (nickname.substr(0, 9) + ".") : nickname) << "|"; 
    std::cout << std::endl;
}
void Contact::ft_print_var() const{
        std::cout << "First Name:         " << first_name << std::endl;
        std::cout << "Last Name:          " << last_name << std::endl;
        std::cout << "Nickname:           " << nickname << std::endl;
        std::cout << "Phone Number:       " << nbr_phone << std::endl;
        std::cout << "The Darkest Secret: " << dark_secret << std::endl;
}