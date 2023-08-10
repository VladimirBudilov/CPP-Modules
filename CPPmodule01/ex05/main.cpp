#include "Harl.h"

int main()
{
	Harl harl = Harl();

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

/*	harl.complain("dEBUG");
	harl.complain("iNFO");
	harl.complain("wARNING");
	harl.complain("eRROR");
	harl.complain("WRONG");

	harl.complain("");
	harl.complain(" ");
	harl.complain("                                                ");
	harl.complain("DEBUG ");
	harl.complain(" INFO");

	harl.complain("WARNING ");
	harl.complain("1");
	harl.complain("2");
	harl.complain("3");
	harl.complain("11111111111111111111111111111111111111111111111");*/
	//system("leaks Harl_2.0");
	return 0;
}