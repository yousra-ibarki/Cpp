#include "PhoneBook.hpp"
std::string ft_commands()
{
    std::string command;

    std::cout << "\nEnter One Of The Following Commands :\nADD:    Save a new contact\nSEARCH: Display a specific contact\nEXIT:   Quit\n";
    std::getline(std::cin, command);
    return command;
}

// std::string ft_space(std::string str, std::string out)
// {
//     int i;
//     int j = 0;
//     int len = str.length();

//     i = (10 - len);
//     while (i < 10)
//     {
//         out[i] = str[j];
//         i++;
//         j++;
//         if (len > 10)
//             out[9] = '.';
//     }
//     return out;
// }

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
            //contact.first_name = ft_space(contact.first_name, out);

            std::cout << "Enter The Last Name :";
            std::getline(std::cin, contact.last_name);
            //contact.last_name = ft_space(contact.last_name, out);

            std::cout << "Enter The Nickname :";
            std::getline(std::cin, contact.nickname);
            //contact.nickname = ft_space(contact.nickname, out);

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
            if (int_index <= 0 || int_index > count_contacts || !checkDigit(index))
                std::cout << "\nIncorrect Or Index Out Of Range\n";
            else
                book.ft_searchable(int_index - 1);
        }
    } while (command != "EXIT");
}