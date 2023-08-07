#include "PhoneBook.h"

void PhoneBook::addUser() {
    if (this->index == 8)
        this->index = 0;
    this->contacts[this->index].AddContact();
    this->index++;
}

PhoneBook::PhoneBook() {
    this->index = 0;
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::SearchUser() {
    this->PrintContacts();
    std::string index;
    std::cout << "Enter index: ";
    std::cin >> index;
    this->PrintContactInfo(index);
}

void PhoneBook::PrintContacts() {
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < this->index; i++) {
        this->contacts[i].PrintContact(i);
    }
}

void PhoneBook::PrintContactInfo(std::string index) {
    int i = std::(index);
    if (i < 0 || i > 7 || i >= this->index) {
        std::cout << "Wrong index" << std::endl;
        return;
    }

}
