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

bool ScalarConverter::IsChar(const std::string &string)
{
	return string.length() == 1 && !std::isdigit(string[0]);
}

bool ScalarConverter::IsInt(const std::string &string)
{
	std::istringstream inputStringStream(string);
	int number;
	inputStringStream >> number;
	return !inputStringStream.fail() && inputStringStream.eof();
}

bool ScalarConverter::IsFloat(const std::string &string)
{
	const char* constString = string.c_str();
	char* endPtr;
	double number = atof(constString);
	if (number == 0 && constString[0] != '0')
		return false;
	
	while (*endPtr != '\0')
	{
		if (*endPtr != 'f')
			return false;
		++endPtr;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &str)
{
	const char* cstr = str.c_str();
	char* endptr;
	std::strtod(cstr, &endptr);
	if (endptr == cstr)
		return false;
	while (*endptr != '\0')
	{
		if (*endptr != 'f')
			return false;
		++endptr;
	}
	return true;
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



const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}
