#include "ScalarConverter.h"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}



void ScalarConverter::convertToChar(const std::string &str)
{
	char    c = str[0];
	if (c >= 0 && c <= 127)
	{
		if (isprint(c) == 0)
			std::cout << "char:   Non displayable" << std::endl;
		else
			std::cout << "char:   " << c << std::endl;
	}
	else
		std::cout << "char:   impossible" << std::endl;
	std::cout << "int:    " << static_cast<int>(c) << std::endl;
	std::cout << "float:  " << static_cast<float>(c)  <<".0f"<< std::endl;
	std::cout << "double: " << static_cast<double>(c) <<".0"<< std::endl;
}

void ScalarConverter::convertToInt(const std::string &str)
{

}

void ScalarConverter::convertToFloat(const std::string &str)
{

}

void ScalarConverter::convertToDouble(const std::string &str)
{

}

void ScalarConverter::convert(const std::string &str)
{

}

bool ScalarConverter::isChar(const std::string &str)
{
	return str.length() == 1 && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string &str)
{
	std::istringstream iss(str);
	int n;
	iss >> n;
	return !iss.fail() && iss.eof();
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}
