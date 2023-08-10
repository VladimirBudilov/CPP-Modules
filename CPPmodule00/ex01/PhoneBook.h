#ifndef C__PROJECT_PHONEBOOK_H
#define C__PROJECT_PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
    Contact contacts[8];
    int index;
	int size;
public:
    PhoneBook();
    ~PhoneBook();
    void addUser();
    void SearchUser();
    void PrintContacts();
    void PrintContactInfo(std::string index);
};


#endif //C__PROJECT_PHONEBOOK_H
