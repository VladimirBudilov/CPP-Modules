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

	static bool IsChar(const std::string &string);
	static bool IsInt(const std::string &string);
	static bool IsFloat(const std::string &string);
	static bool IsDouble(const std::string &string);
	static bool IsScienceValue(const std::string &string);
	static void ConvertToChar(const std::string &string);
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

private:
	enum e_type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE
	};

	static int GetType(const std::string &basicString);
};


#endif //C__CIRCLE_SCALARCONVERTER_H
