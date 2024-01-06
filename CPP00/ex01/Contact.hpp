#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"

class Contact{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string nbr_phone;
    std::string dark_secret;

public:
    void ft_add_name(const std::string &new_name, const std::string &new_last, const std::string &new_nickname);
    void ft_add_nbrPhone(const std::string &new_nbrPhone, const std::string &new_secret);
    void ft_print() const;
    void ft_print_var() const;
};


#endif 