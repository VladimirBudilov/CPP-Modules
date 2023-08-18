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
	const char *constString = string.c_str();
	char *endPtr;
	double number = atof(constString);
	if (number == 0 && constString[0] != '0')
		return false;
	endPtr = const_cast<char *>(constString) + std::strlen(constString);
	if (*endPtr != 'f')
		return false;
	while (endPtr > constString && std::isspace(*(endPtr - 1))) {
		--endPtr;
		if (*endPtr == 'f') {
			++endPtr;
			while (*endPtr != '\0') {
				if (!std::isspace(*endPtr)) {
					return false;
				}
				++endPtr;
			}
			return true;
		}
		return false;
	}
	return true;
}

bool ScalarConverter::IsDouble(const std::string &string)
{
	const char *constString = string.c_str();
	char *endptr;
	std::strtod(constString, &endptr);
	if (endptr == constString)
		return false;
	while (*endptr != '\0') {
		if (*endptr != 'f')
			return false;
		++endptr;
	}
	return true;
}

void ScalarConverter::ConvertToChar(const std::string &string)
{
	char chr = string[0];
	if (chr >= 0 && chr <= 127) {
		if (isprint(chr) == 0)
			std::cout << "char:   Non displayable" << std::endl;
		else
			std::cout << "char:   " << chr << std::endl;
	} else
		std::cout << "char:   impossible" << std::endl;
	std::cout << "int:    " << static_cast<int>(chr) << std::endl;
	std::cout << "float:  " << static_cast<float>(chr) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
}

void ScalarConverter::convertToInt(const std::string &str)
{
	int n = std::atoi(str.c_str());

	if (n < -128 || n > 127)
		std::cout << "char:   impossible" << std::endl;
	else if (n >= 32 && n < 127)
		std::cout << "char:   " << static_cast<char>(n) <<  std::endl;
	else
		std::cout << "char:   Non displayable" << std::endl;
	std::cout << "int:    " << static_cast<int>(n) << std::endl;
	std::cout << "double: " << static_cast<double>(n) <<".0"<< std::endl;
	std::cout << "float:  " << static_cast<float>(n) <<".0f"<< std::endl;
}

void ScalarConverter::convertToFloat(const std::string &str)
{
	double number = std::strtod(str.c_str(), NULL);

	if (IsScienceValue(str) || number < -128 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (number >= 32 && number < 127)
		std::cout << "char: " << static_cast<char>(number) <<  std::endl;
	else
		std::cout << "char: Non Displayable" << std::endl;
	if (IsScienceValue(str) || number > INT_MAX || number < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: "  << static_cast<float>(number)  <<"f"<< std::endl;
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void ScalarConverter::convertToDouble(const std::string &str)
{
	double number = std::strtod(str.c_str(), NULL);

	if (IsScienceValue(str) || number < -128 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (number >= 32 && number < 127)
		std::cout << "char: " << static_cast<char>(number) <<  std::endl;
	else
		std::cout << "char: Non Displayable" << std::endl;
	if (IsScienceValue(str) || number > INT_MAX || number < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: "    << static_cast<int>(number) << std::endl;
	std::cout << "float: "  << static_cast<float>(number)  <<"f"<< std::endl;
	std::cout << "double: " << number << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	try{
		switch(GetType(str)) {
			case CHAR:
				ConvertToChar(str);
				break;
			case INT:
				convertToInt(str);
				break;
			case FLOAT:
				convertToFloat(str);
				break;
			case DOUBLE:
				convertToDouble(str);
				break;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

bool ScalarConverter::IsScienceValue(const std::string &string)
{
	if (string == "inf" || string == "+inf" || string == "-inf" || string == "inff" || string == "+inff" || string == "-inff" || string == "nan" || string == "nanf")
		return true;
	return false;
}

int ScalarConverter::GetType(const std::string &basicString)
{
	if (IsChar(basicString))
		return CHAR;
	else if (IsInt(basicString))
		return INT;
	else if (IsFloat(basicString))
		return FLOAT;
	else if (IsDouble(basicString))
		return DOUBLE;
	throw ImpossibleException();
}


const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}
