#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
private:
    static const int max_size = 2;
    int i;
    int count_contacts;
    Contact contacts[max_size];
public:
    PhoneBook();
    void ft_add_to_PhoneBook(const std::string &name, const std::string &last, const std::string &nickname, const std::string &nbrPhone, const std::string &secret);
    void ft_display_PhoneBook() const;
    void ft_searchable(int index) const;
};

typedef struct s_contact
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string nbr_phone;
    std::string dark_secret;
} t_contact;


#endif 