#include "Harl.h"

void ValidateInfo(int argc, char **argv, int &lvl);

int main(int argc, char **argv)
{
	int lvl = -1;
	Harl harl = Harl();

	ValidateInfo(argc, argv, lvl);

	harl.Filter("DEBUG", lvl);
	harl.Filter("INFO", lvl);
	harl.Filter("WARNING", lvl);
	harl.Filter("ERROR", lvl);
	harl.Filter(" ERROR", lvl);
	harl.Filter("ER", lvl);
	harl.Filter("     ", lvl);
	//system("leaks harlFilter");
	return 0;
}