#include "Replacer2000.h"

int main(int argc, char **argv)
{
	Replacer2000 replacer = Replacer2000();
	replacer.ValidateArgc(argc);
	replacer.ValidateArgs(argv[1], argv[2], argv[3]);
	replacer.ReadFile();
	replacer.Replace();
	replacer.WriteFile();
	return 0;
}