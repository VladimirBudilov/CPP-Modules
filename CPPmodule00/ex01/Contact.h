#ifndef C__PROJECT_CONTACT_H
#define C__PROJECT_CONTACT_H

#include "iostream"
#include <iomanip>

class Contact {
private:
    std::string	firstName;
    std::string	lastName;
    std::string	nickname;
    std::string	phoneNumber;
    std::string	darkestSecret;
public:
    Contact();
    ~Contact();
    void ValidateInfo(std::string &data);
    void AddInfo(std::string &field, const std::string& field_name);
    void AddContact();
    void PrintContact(int i);
	void PrintContactInfo();
};

#endif //C__PROJECT_CONTACT_H
