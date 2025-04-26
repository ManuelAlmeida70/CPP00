#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact( std::string firstName, std::string lastName, std::string phoneNumber, std::string darkestSecret) : firsName(firsName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret)
{}

std::string Contact::getFirstName() const 
{
    return this->firsName;
}

std::string Contact::getLastName() const
{
    return this->lastName;
}

std::string Contact::getNickname() const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkSecret() const
{
    return this->darkestSecret;
}

bool Contact::isEmpty() const
{
    return firsName.empty();
}