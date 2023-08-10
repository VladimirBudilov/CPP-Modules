#include <fstream>
#include "Replacer2000.h"

Replacer2000::Replacer2000()
{
	_filename = "";
	_s1 = "";
	_s2 = "";
}

Replacer2000::~Replacer2000()
{

}

void Replacer2000::ValidateArgs(std::string filename, std::string s1, std::string s2)
{
	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cout << "Error: empty argument" << std::endl;
		exit(1);
	}
	Replacer2000::_filename = filename;
	Replacer2000::_s1 = s1;
	Replacer2000::_s2 = s2;
}

void Replacer2000::ValidateArgc(int argc)
{
	if (argc != 4) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		exit(1);
	}
}

void Replacer2000::ReadFile()
{
	std::ifstream inputFile(_filename);
	if (!inputFile) {
		std::cout << "Error: Cannot open input file " << _filename << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		_fileContent += line + "\n";
	}
	if(_fileContent.empty()) {
		std::cout << "Error: empty file" << std::endl;
		exit(1);
	}
	inputFile.close();
}

void Replacer2000::Replace()
{
	std::size_t pos;
	std::size_t prevPos = 0;

	while ((pos = _fileContent.find(_s1, prevPos)) != std::string::npos) {
		_newFileContent += _fileContent.substr(prevPos, pos - prevPos);
		_newFileContent += _s2;
		prevPos = pos + _s1.length();
	}
	_newFileContent += _fileContent.substr(prevPos);
}

void Replacer2000::WriteFile()
{
	std::ofstream outputFile(_filename + ".replace");
	if (!outputFile) {
		std::cout << "Error: Cannot open output file " << _filename << ".replace" << std::endl;
		exit(1);
	}
	outputFile << _newFileContent;
	outputFile.close();
}
