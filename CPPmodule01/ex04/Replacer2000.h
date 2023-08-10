#ifndef C__CIRCLE_REPLACER2000_H
#define C__CIRCLE_REPLACER2000_H

#include "iostream"

class Replacer2000 {
private:
	std::string _filename;
	std::string _s1;
	std::string _s2;
	std::string _fileContent;
	std::string _newFileContent;
public:
	Replacer2000();
	~Replacer2000();
	void ValidateArgs(std::string filename, std::string s1, std::string s2);
	void ValidateArgc(int argc);
	void ReadFile();
	void Replace();
	void WriteFile();
};


#endif //C__CIRCLE_REPLACER2000_H
