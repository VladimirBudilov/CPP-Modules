#include <sstream>
#include "PhoneBook.h"

void PhoneBook::addUser() {
    if (index == 8)
        index = 0;
    contacts[index].AddContact();
    index++;
	if(size < 8)
		size++;
}

PhoneBook::PhoneBook() {
    index = 0;
	size = 0;
}

void PhoneBook::SearchUser() {
    this->PrintContacts();
    std::string index;
    std::cout << "Enter index: ";
	std::getline(std::cin, index);
    this->PrintContactInfo(index);
}

void PhoneBook::PrintContacts() {
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    for (int i = 0; i < size; i++) {
        contacts[i].PrintContact(i);
    }
}

void PhoneBook::PrintContactInfo(std::string index) {

	std::istringstream is(index);
	int i;
	if (!(is >> i)){
		std::cout << "Wrong index" << std::endl;
		return;
	}if (index.length() != 1) {
		std::cout << "Wrong index" << std::endl;
		return;
	}
	if (i < 0 || i > 7 || i >= this->size) {
		std::cout << "Wrong index" << std::endl;
		return;
	}
	contacts[i].PrintContactInfo();
}

PhoneBook::~PhoneBook()
{

}
