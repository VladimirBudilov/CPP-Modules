#include "PhoneBook.h"

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        if (command == "EXIT") {
            break;
        } else if (command == "ADD") {
            phoneBook.addUser();
        } else if (command == "SEARCH") {
            phoneBook.SearchUser();
        }
    }
    return 0;
}