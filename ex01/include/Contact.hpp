#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firsName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();
        Contact( std::string firstName, std::string lastName, std::string phoneNumber, std::string darkestSecret);

        void setName( std::string );
        void setLastName( std::string);
        void setNickname( std::string);
        void setPhoneNumber( std::string);
        void setDarkSecret( std::string );
        

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkSecret() const;

        bool isEmpty() const;
};

#endif