#include "Harl.h"

void GetLvl(std::string level, int &lvl);

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout
			<< "I cannot believe adding extra bacon costs more money. You didn’t put 	enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout
			<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
			<< std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*ptr_complain[i])();
			return;
		}
	}
	std::cout << "[Probably complaining about insignificant problems]" << std::endl;
}

void Harl::Filter(std::string command, int lvl)
{
	switch (CompareCommandAndLvl(lvl, command)) {
		case (0):
			this->complain("DEBUG");
			break;
		case (1):
			this->complain("INFO");
			break;
		case (2):
			this->complain("WARNING");
			break;
		case (3):
			this->complain("ERROR");
			break;
		default:
			std::cout << "Harl complaining about something but it's out of filter lvl" << std::endl;
			break;
	}
}

int Harl::CompareCommandAndLvl(int lvl, std::string &command)
{
	int commandLvl = -1;
	GetLvl(command, commandLvl);
	switch (commandLvl) {
		case (0):
			if (lvl == 0)
				return (0);
			break;
		case (1):
			if (lvl == 0 || lvl == 1)
				return (1);
			break;
		case (2):
			if (lvl == 0 || lvl == 1 || lvl == 2)
				return (2);
			break;
		case (3):
			if (lvl == 3 || lvl == 0 || lvl == 1 || lvl == 2)
				return (3);
			break;
		default:
			return (-1);
	}
	return (-1);
}

void ValidateInfo(int argc, char **argv, int &lvl)
{
	if (argc != 2) {
		std::cout << "Harl complaining that you give wrong number of arguments" << std::endl;
		exit(1);
	}
	std::string level = argv[1];
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
		std::cout << "Harl complaining that you give wrong level filter" << std::endl;
		exit(1);
	}
	GetLvl(level, lvl);
}

void GetLvl(std::string level, int &lvl)
{
	int lvls[4] = {0, 1, 2, 3};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			lvl = lvls[i];
			return;
		}
	}
}