/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <maalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:06:25 by maalmeid          #+#    #+#             */
/*   Updated: 2025/04/28 10:06:30 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

void PhoneBook::addContact(const Contact& contact)
{
    if (count < 8)
    {
        contacts[count] = contact;
        count++;
    }
    else
    {
        contacts[oldest] = contact;
        oldest = (oldest + 1) % 8;
    }
}

void PhoneBook::displayContactList() const
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|";

        std::string firstName = contacts[i].getFirstName();
        if (firstName.length() > 10)
            std::cout << std::setw(10) << firstName.substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << firstName << "|";
        
        std::string lastName = contacts[i].getLastName();
        if (lastName.length() > 10)
            std::cout << std::setw(10) << lastName.substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << lastName << "|";
        
        std::string nickname = contacts[i].getNickname();
        if (nickname.length() > 10)
            std::cout << std::setw(10) << nickname.substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << nickname << "|";
    }
}


void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName();
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkSecret() << std::endl;
}


void PhoneBook::searchContact() const
{
    int index;

    if (count == 0)
    {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }

    displayContactList();

    std::cout << "\nEnter the index of the contact you want to display: ";
    std::cin >> index;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input!" << std::endl;
        return;
    }

    displayContact(index);
}