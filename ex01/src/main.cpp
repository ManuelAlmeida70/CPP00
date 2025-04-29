/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <maalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:06:47 by maalmeid          #+#    #+#             */
/*   Updated: 2025/04/29 10:50:43 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <algorithm>

std::string trim(const std::string& str)
{
    size_t start;
    size_t end;

    start = 0;
    while (start < str.length() && std::isspace(str[start]))
        start++;
    
    end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
    
}

std::string get_non_empty_line(const std::string& prompt)
{
    std::string input;
    
    do
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        input = trim(input);
        if (input.empty())
            std::cout << "Field cannot be empty.\n";
    } while (input.empty());

    return input;
    
}

bool is_digits_only(const std::string& str)
{
    if (str.empty()) return false;
    
    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    return true;
}

Contact createContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    firstName = get_non_empty_line("Enter First Name: ");
    
    lastName = get_non_empty_line("Enter Last Name: ");
    
    nickname = get_non_empty_line("Enter Nickname: ");
    
    do
    {
        phoneNumber = get_non_empty_line("Enter Phone Number: ");
        if (!is_digits_only(phoneNumber))
            std::cout << "Invalid phone number. use digits only.\n";
    }while (!is_digits_only(phoneNumber));

    darkestSecret = get_non_empty_line("Enter Darkest Secret: ");
    
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
        
        command.erase(std::remove(command.begin(), command.end(), ' '), command.end());
        
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