#include "PhoneBook.hpp"
#include "Contact.hpp"

void ft_check_good(std::string& str)
{
    std::getline(std::cin, str);
    if(!std::cin.good())
        exit(1);
}

std::string ft_commands()
{
    std::string command;

    std::cout << "\nEnter One Of The Following Commands :\nADD:    Save a new contact\nSEARCH: Display a specific contact\nEXIT:   Quit\n";
    ft_check_good(command);
    return command;
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
            do{
                std::cout << "Enter The First Name :";
                ft_check_good(contact.first_name);
            } while(contact.first_name.empty());
            do{
                std::cout << "Enter The Last Name :";
                ft_check_good(contact.last_name);
            } while(contact.last_name.empty());
            do{
                std::cout << "Enter The Nickname :";
                ft_check_good(contact.nickname);
            } while(contact.nickname.empty());
            do{
                std::cout << "Enter The Phone Number :";
                ft_check_good(contact.nbr_phone);
            } while(contact.nbr_phone.empty());
            do{
                std::cout << "Enter The Darkest Secret :";
                ft_check_good(contact.dark_secret);
            } while(contact.dark_secret.empty());

            book.ft_add_to_PhoneBook(contact.first_name, contact.last_name, contact.nickname, contact.nbr_phone, contact.dark_secret);
            std::cout << "\nYour Contact Has Been Added Seccessfully.\n";
            if(count_contacts < 2)
                count_contacts++;
            
        }
        else if (command == "SEARCH")
        { 
            book.ft_display_PhoneBook();
            std::cout << "\nEnter The Index Of The Contact That You Want To See\n";
            ft_check_good(index);
            int_index = std::atoi(index.c_str());
            if (int_index <= 0 || int_index > count_contacts || !checkDigit(index))
                std::cout << "\nIncorrect Or Index Out Of Range\n";
            else
                book.ft_searchable(int_index - 1);
        }
    } while (command != "EXIT");
}