#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int count;
        int oldest;

    public:
        PhoneBook();
        void addContact(const Contact& contact);
        void searchContact() const;
        void displayContactList() const;
        void displayContact(int index) const;
};

#endif