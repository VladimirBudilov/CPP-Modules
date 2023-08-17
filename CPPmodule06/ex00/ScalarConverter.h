#ifndef C__CIRCLE_SCALARCONVERTER_H
#define C__CIRCLE_SCALARCONVERTER_H

#include "iostream"
#include <sstream>

class ScalarConverter {
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	virtual ~ScalarConverter();

	static bool isChar(std::string const &str);
	static bool isInt(std::string const &str);
	static bool isFloat(std::string const &str);
	static bool isDouble(std::string const &str);
	static void convertToChar(std::string const &str);
	static void convertToInt(std::string const &str);
	static void convertToFloat(std::string const &str);
	static void convertToDouble(std::string const &str);
	static void convert(std::string const &str);
	class ImpossibleException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NonDisplayableException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};


#endif //C__CIRCLE_SCALARCONVERTER_H
