#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook() : i(0), count_contacts(0) {}

void PhoneBook:: ft_add_to_PhoneBook(const std::string &name, const std::string &last, const std::string &nickname, const std::string &nbrPhone, const std::string &secret){

    if (i < count_contacts)
    {
        contacts[i].ft_add_name(name, last, nickname);
        contacts[i].ft_add_nbrPhone(nbrPhone, secret);
        count_contacts++;
        i = (i + 1) % max_size;
    }
    else
    {
        contacts[i].ft_add_name(name, last, nickname);
        contacts[i].ft_add_nbrPhone(nbrPhone, secret);
        i = (i + 1) % max_size;
        count_contacts++;
    }
}

void PhoneBook::ft_display_PhoneBook() const{
    int i;

    i = 0;
        std::cout << "____________________________________________\n";
        std::cout << "     Index|First Name| Last Name|  Nickname|\n";
        while (i < count_contacts)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        contacts[i].ft_print();
        i++;
    }
}

void PhoneBook:: ft_searchable(int index) const{
    contacts[index].ft_print_var();
}
