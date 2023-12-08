#include <iostream>
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
    Contact() : first_name(10, '\0'), last_name(10, '\0'), nickname(10, '\0'){}

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
    void ft_print2() const{
        std::cout << "First Name:         " <<first_name << std::endl;
        std::cout << "Last Name:          "  << last_name << std::endl;
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

    void ft_searchable(int index) const{
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

    // do
    // {
        std::cout << "\nEnter One Of The Following Commands :\nADD:    Save a new contact\nSEARCH: Display a specific contact\nEXIT:   Quit\n";
        std::getline(std::cin, command);
    // } while (command != "ADD" && command != "SEARCH" && command != "EXIT");
    return command;
}



std::string ft_space(std::string str, std::string out)
{
    int i = 0;
    int j = 0;
    int len = str.length();
   
    while(i < (10 - len))
    {
        out[i] = ' ';
        i++;
    }
   while(i < 10)
    {
        out[i] = str[j];
        i++;
        j++;
        if(len > 10)
            out[9] = '.';
    }
    return out;
} 

int main()
{
    PhoneBook book;
    t_contact contact;
    std::string command;
    std::string out(10, ' ');
    int count_contacts;
    int index;
    int i;

    i = 0;
    count_contacts = 0;
    do
    {
        command = ft_commands();
        if (command == "ADD")
        {
            std::cout << "Enter The First Name ";
            std::getline(std::cin, contact.first_name);
            contact.first_name = ft_space(contact.first_name, out);

            std::cout << "Enter The Last Name ";
            std::getline(std::cin, contact.last_name);
            contact.last_name = ft_space(contact.last_name, out);

            std::cout << "Enter The Nickname ";
            std::getline(std::cin, contact.nickname);
            contact.nickname = ft_space(contact.nickname, out);

            std::cout << "Enter The Phone Number ";
            std::getline(std::cin, contact.nbr_phone);

            std::cout << "Enter The Darkest Secret ";
            std::getline(std::cin, contact.dark_secret);
            
            book.ft_add_to_PhoneBook(contact.first_name, contact.last_name, contact.nickname, contact.nbr_phone, contact.dark_secret);
            std::cout << "\nYour Contact Has Been Added Seccessfully.\n";
            count_contacts++;
        }
        else if (command == "SEARCH")
        {
            book.ft_display_PhoneBook();
            std::cout << "\nEnter The Index Of The Contact That You Want To See\n";
            std::cin >> index;
            if(index < 0 || index > count_contacts)
                std::cout << "Index Out Of Range";
            else
                book.ft_searchable(index-1);
        }
    } while (command != "EXIT");
}