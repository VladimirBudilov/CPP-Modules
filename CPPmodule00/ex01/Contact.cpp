#include "Contact.h"

void Contact::AddContact() {
    AddInfo(firstName, "firstName");
    AddInfo(lastName, "lastName");
    AddInfo(nickname, "nickname");
    AddInfo(phoneNumber, "phoneNumber");
    AddInfo(darkestSecret, "darkestSecret");
}

void Contact::AddInfo(std::string &field, const std::string& field_name) {

    std::string data;
    std::cout << "Enter " << field_name << ": ";
    std::getline(std::cin, data);
    ValidateInfo(data);
    field = data;
}

void Contact::ValidateInfo(std::string &data) {
    while (data.empty()) {
        std::cout << "Field is empty" << std::endl;
        std::cout << "Enter field again: ";
        std::getline(std::cin, data);
    }
}

void Contact::PrintContact(int i) {
	std::cout << "|";
    std::cout << std::setw(10) << i << "|";
    if (firstName.length() > 10)
        std::cout << firstName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << firstName << "|";
    if (lastName.length() > 10)
        std::cout << lastName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << lastName << "|";
    if (nickname.length() > 10)
        std::cout << nickname.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << nickname << "|";
    std::cout << std::endl;
}

void Contact::PrintContactInfo()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

Contact::Contact()
{

}

Contact::~Contact()
{

}
