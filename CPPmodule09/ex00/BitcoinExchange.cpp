#include "BitcoinExchange.hpp"

std::set<std::string> BitcoinExchange::_uniqueDates;
std::map<std::string, float> BitcoinExchange::_exchangeDataMap;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    if (this != &rhs) {}
    return *this;
}

///File validation
void BitcoinExchange::IsValidSourceFile() {
    std::ifstream inputFile("data.csv");
    if (!inputFile.is_open()) {
        std::cout << "File is incorrect: could not open file." << std::endl;
        inputFile.close();
        throw std::invalid_argument("Invalid source file");
    }
    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != "date,exchange_rate") {
        std::cout << "File is incorrect: incorrect first line." << std::endl;
        inputFile.close();
        throw std::invalid_argument("Invalid source file");

    }
}

void BitcoinExchange::IsValidInputFile(const std::string &fileName) {
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open()) {
        throw std::invalid_argument("Invalid input file");
    }
    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != "date | value") {
        throw std::invalid_argument("Invalid input file");
    }
    inputFile.close();
}

///Date format validation
bool BitcoinExchange::IsValidDateFormat(const std::string &data) {
    int year, month, day;
    GetDataNumbers(data, year, month, day);
    if (
            !IsValidDateNumbers(year, month, day) ||
            !IsValidLeapYear(year, month, day))
        return false;
    return true;
}

bool BitcoinExchange::IsValidDateNumbers(int year, int month, int day) {
    if (!(year < 1900 || year > 2023 || month < 1 || month > 12 || day < 1))
        return true;
    std::cout << "Invalid date format" << std::endl;
    return false;
}

bool BitcoinExchange::IsValidLeapYear(int year, int month, int day) {

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month != 2 && (day > daysInMonth[month])) {
        std::cout << "Invalid date format in leap year" << std::endl;
        return false;
    }
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && day > 29) {
            std::cout << "Invalid date format in in leap year" << std::endl;
            return false;
        } else if (!isLeapYear && day > 28) {
            std::cout << "Invalid date format in leap year" << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::IsUniqueDate(std::string &dateStr) {
    if (BitcoinExchange::_uniqueDates.find(dateStr) != BitcoinExchange::_uniqueDates.end()) {
        std::cout << "Error: duplicate date => " << dateStr << std::endl;
        return false;
    }
    return true;
}

///Exchange rate validation
bool BitcoinExchange::IsValidExchangeRate(const std::string &rate) {
    std::istringstream exchangeRateStream(rate);
    float exchangeRate;
    std::string trash;
    if (exchangeRateStream >> exchangeRate) {
        if (getline(exchangeRateStream, trash)) {
            std::cout << "Invalid exchange rate" << std::endl;
            return false;
        }
        if (exchangeRate >= 0.0f)
            return true;
    }
    std::cout << "Invalid exchange rate" << std::endl;
    return false;
}

///Header validation
bool BitcoinExchange::IsValidInputFileHeader(const std::string &data) {
    if (data[4] != '-' || data[7] != '-') {
        std::cout << "Invalid date format in file" << std::endl;
        return false;
    }
    for (int i = 0; i < 10; ++i) {
        if (i != 4 && i != 7 && !isdigit(data[i])) {
            std::cout << "Invalid date format in file" << std::endl;
            return false;
        }
    }
    return true;
}

///Files content validation
bool BitcoinExchange::ValidateSourceFile() {
    std::ifstream inputFile("data.csv");
    int lineNumber = 2;
    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, exchangeRateStr;
        if (std::getline(ss, dateStr, ',') && std::getline(ss, exchangeRateStr)) {
            if (!IsValidDateFormat(dateStr) || !IsValidExchangeRate(exchangeRateStr) || !IsUniqueDate(dateStr)) {
                std::cout << "Error: in source invalid line => " << lineNumber << std::endl;
                return false;
            }
            else{
                BitcoinExchange::_uniqueDates.insert(dateStr);
            }
        } else {
            std::cout << "Error: in source invalid line => " << lineNumber << std::endl;
            return false;
        }
        ++lineNumber;
    }
    inputFile.close();
    return true;
}

///Parsing input and source file
void BitcoinExchange::ParseInputFile(const std::string &fileName) {
    std::ifstream inputFile(fileName.c_str());

    std::string line;
    std::getline(inputFile, line);

    while (getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string date;
        float value;
        char c;
        if (LineValidation(line) && ss >> date >> c >> value && ss.eof()) {
            if (!IsValidDateFormat(date)) {
                std::cout << "Error: bad input => " << date << std::endl;
            } else if (value < 0.0f) {
                std::cout << "Error: not a positive number." << std::endl;
            } else if (value > 1000.0f) {
                std::cout << "Error: too large a number." << std::endl;
            } else
                ShowExchangeRate(date, value);
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }

    }
}

void BitcoinExchange::ParseSourceFile() {

    std::ifstream inputFile("data.csv");
    if (!inputFile.is_open()) {
        std::cout << "Error, could not open source file." << std::endl;
        return;
    }
    std::string firstLine;
    std::getline(inputFile, firstLine);

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, exchangeRateStr;
        if (std::getline(ss, dateStr, ',') && std::getline(ss, exchangeRateStr)) {
            _exchangeDataMap[dateStr] = static_cast<float>(atof(exchangeRateStr.c_str()));
        }
    }
}

void BitcoinExchange::Convert(const std::string &fileName) {

    IsValidSourceFile();
    IsValidInputFile(fileName);
    if (!ValidateSourceFile())
        return;
    ParseSourceFile();
    ParseInputFile(fileName);
}

/// Tools
void BitcoinExchange::ShowExchangeRate(const std::string &line, float value) {

    std::map<std::string, float>::const_iterator it;
    it = BitcoinExchange::_exchangeDataMap.begin();

    if (line < it->first) {
        std::cout << line << " => 0 (no info)" << std::endl;
        return;
    }

    for (; it != BitcoinExchange::_exchangeDataMap.end(); ++it) {
        if (it->first > line && it != BitcoinExchange::_exchangeDataMap.begin()) {
            --it;
            std::cout << line << " => " << it->second * value << std::endl;
            return;
        }

        if (it->first == line) {
            std::cout << line << " => " << it->second * value << std::endl;
            return;
        }
    }
    --it;
    std::cout << line << " => " << it->second * value << std::endl;
}

bool BitcoinExchange::LineValidation(std::string line) {

    if (isdigit(line[0]) == false || line[10] != ' ' || line[11] != '|' || line[12] != ' ' ||
        (isdigit(line[13]) == false && line[13] != '-')) {
        return false;
    }
    return true;
}

void BitcoinExchange::GetDataNumbers(const std::string &data, int &year, int &month, int &day) {
    year = atoi(data.substr(0, 4).c_str());
    month = atoi(data.substr(5, 2).c_str());
    day = atoi(data.substr(8, 2).c_str());
}
