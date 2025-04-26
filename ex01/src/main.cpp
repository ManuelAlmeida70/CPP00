#include "PhoneBook.hpp"
#include <iostream>
#include <string>

Contact createContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    while (firstName.empty())
    {
        std::cout << "Field cannot be empty. Enter First Name: ";
        std::getline(std::cin, firstName);
    }

    std::cout << "Enter Last name: ";
    std::getline(std::cin, lastName);
    while (lastName.empty())
    {
        std::cout << "Field cannot be empty. Enter Last Name: ";
        std::getline(std::cin, lastName);
    }

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    while (nickname.empty())
    {
        std::cout << "Field cannot be empty. Enter Nickname: ";
        std::getline(std::cin, nickname);
    }

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    while (darkestSecret.empty())
    {
        std::cout << "Field cannot be empty. Enter Darkest Secret: ";
        std::getline(std::cin, darkestSecret);
    }

    return Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            Contact newContact = createContact();
            PhoneBook.addContact(newContact);
        }
        else if (command == "SEARCH")
            PhoneBook.searchContact();
        else if (command == "EXIT")
            break;
    }

    return 0;
}