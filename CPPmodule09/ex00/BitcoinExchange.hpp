#ifndef C__CIRCLE_BITCOINEXCHANGE_HPP
#define C__CIRCLE_BITCOINEXCHANGE_HPP

#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include "iostream"

class BitcoinExchange {
private:
    static std::set<std::string> _uniqueDates;
    static std::map<std::string, float> _exchangeDataMap;

    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);

    static bool IsValidDateFormat(const std::string &data);
    static bool IsValidDateNumbers(int year, int month, int day);
    static bool IsValidLeapYear(int year, int month, int day);
    static bool IsValidInputFileHeader(const std::string &data);
    static bool IsValidExchangeRate(const std::string &rate);
    static bool IsUniqueDate(std::string &dateStr);

    static void GetDataNumbers(const std::string &data, int &year, int &month, int &day);
    static bool LineValidation(std::string line);

    static void IsValidInputFile(const std::string &fileName);
    static void IsValidSourceFile();

    static void ParseInputFile(const std::string &fileName);
    static void ParseSourceFile();

    static bool ValidateSourceFile();
    static void ShowExchangeRate(const std::string &line, float value);
public:
    static void Convert(std::string const &fileName);
};

#endif //C__CIRCLE_BITCOINEXCHANGE_HPP
