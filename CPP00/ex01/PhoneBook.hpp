#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <string>

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

class PhoneBook{
private:
    static const int max_size = 8;
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