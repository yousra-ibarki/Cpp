/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:57:48 by yoibarki          #+#    #+#             */
/*   Updated: 2023/12/09 15:28:11 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string nbr_phone;
    std::string dark_secret;

public:

    void ft_add_name(const std::string &new_name, const std::string &new_last, const std::string &new_nickname)
    {
        first_name = new_name;
        last_name = new_last;
        nickname = new_nickname;
    }
    void ft_add_nbrPhone(const std::string &new_nbrPhon, const std::string &new_secret)
    {
        nbr_phone = new_nbrPhon;
        dark_secret = new_secret;
    }
    void ft_print() const
    {
        std::cout << first_name << "|"
                  << last_name << "|"
                  << nickname << "|"
                  << "\n";
    }
    void ft_print2() const
    {
        std::cout << "First Name:         " << first_name << std::endl;
        std::cout << "Last Name:          " << last_name << std::endl;
        std::cout << "Nickname:           " << nickname << std::endl;
        std::cout << "Phone Number:       " << nbr_phone << std::endl;
        std::cout << "The Darkest Secret: " << dark_secret << std::endl;
    }
};

class PhoneBook
{
private:
    static const int max_size = 8;
    int i;
    int count_contacts;
    Contact contacts[max_size];

public:
    PhoneBook() : i(0), count_contacts(0) {}

    void ft_add_to_PhoneBook(const std::string &name, const std::string &last, const std::string &nickname, const std::string &nbrPhone, const std::string &secret)
    {

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

    void ft_display_PhoneBook() const
    {
        int i;

        i = 0;
        std::cout << "     Index|First Name| Last Name|  Nickname|\n";
        while (i < count_contacts)
        {
            std::cout << i + 1 << "         |";
            contacts[i].ft_print();
            i++;
        }
    }

    void ft_searchable(int index) const
    {
        contacts[index].ft_print2();
    }
};

typedef struct s_contact
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string nbr_phone;
    std::string dark_secret;
} t_contact;

std::string ft_commands()
{
    std::string command;

    std::cout << "\nEnter One Of The Following Commands :\nADD:    Save a new contact\nSEARCH: Display a specific contact\nEXIT:   Quit\n";
    std::getline(std::cin, command);
    return command;
}

std::string ft_space(std::string str, std::string out)
{
    int i;
    int j = 0;
    int len = str.length();

    i = (10 - len);
    while (i < 10)
    {
        out[i] = str[j];
        i++;
        j++;
        if (len > 10)
            out[9] = '.';
    }
    return out;
}

bool checkDigit(std::string str)
{    
    for(int i = 0; str[i] ; i++)
    {
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}
int main()
{
    PhoneBook book;
    t_contact contact;
    std::string command;
    std::string out(10, ' ');
    int count_contacts;
    std::string index;
    int int_index;
    int i;

    i = 0;
    count_contacts = 0;
    do
    {
        command = ft_commands();
        if (command == "ADD")
        {
            std::cout << "Enter The First Name :";
            std::getline(std::cin, contact.first_name);
           contact.first_name = ft_space(contact.first_name, out);

            std::cout << "Enter The Last Name :";
            std::getline(std::cin, contact.last_name);
            contact.last_name = ft_space(contact.last_name, out);

            std::cout << "Enter The Nickname :";
            std::getline(std::cin, contact.nickname);
            contact.nickname = ft_space(contact.nickname, out);

            std::cout << "Enter The Phone Number :";
            std::getline(std::cin, contact.nbr_phone);

            std::cout << "Enter The Darkest Secret :";
            std::getline(std::cin, contact.dark_secret);

            book.ft_add_to_PhoneBook(contact.first_name, contact.last_name, contact.nickname, contact.nbr_phone, contact.dark_secret);
            std::cout << "\nYour Contact Has Been Added Seccessfully.\n";
            count_contacts++;
        }
        else if (command == "SEARCH")
        { 
            book.ft_display_PhoneBook();
            std::cout << "\nEnter The Index Of The Contact That You Want To See\n";
            std::getline(std::cin, index);
            int_index = std::atoi(index.c_str());
            if (int_index < 0 || int_index > count_contacts || !checkDigit(index))
                std::cout << "\nIncorrect Or Index Out Of Range\n";
            else
                book.ft_searchable(int_index - 1);
        }
    } while (command != "EXIT");
}

// ctr-d
// cin.good
// cin.empty
// getline()
// using namespace std;
// int main()
// {
//     string str;
//     getline(cin, str);
//     if (!cin.good())exit(0);
//     while(str.empty())
//         getline(cin, str);
// }