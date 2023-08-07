#include <iomanip>
#include "Contact.h"

Contact::Contact() {

}

Contact::~Contact() {

}

void Contact::AddContact() {
    AddInfo(this->firstName, "firstName");
    AddInfo(this->lastName, "lastName");
    AddInfo(this->nickname, "nickname");
    AddInfo(this->phoneNumber, "phoneNumber");
    AddInfo(this->darkestSecret, "darkestSecret");
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
    std::cout << std::setw(10) << i << "|";
    if (this->firstName.length() > 10)
        std::cout << this->firstName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->firstName << "|";
    if (this->lastName.length() > 10)
        std::cout << this->lastName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->lastName << "|";
    if (this->nickname.length() > 10)
        std::cout << this->nickname.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->nickname << "|";
    std::cout << std::endl;

}
