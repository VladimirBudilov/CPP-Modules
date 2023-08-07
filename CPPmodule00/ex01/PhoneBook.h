#ifndef C__PROJECT_PHONEBOOK_H
#define C__PROJECT_PHONEBOOK_H


#include "Contact.h"
#include "iostream"

class PhoneBook {
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    ~PhoneBook();
    void addUser();
    void SearchUser();

    void PrintContacts();

    void PrintContact(int i);

    void PrintContactInfo(std::string index);
};


#endif //C__PROJECT_PHONEBOOK_H
