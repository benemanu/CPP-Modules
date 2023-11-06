#include "BitcoinExchange.hpp"

std::map<std::string, double> readFile() {
    std::map<std::string, double> _data;
    std::ifstream _file("data.csv");
    std::string line;

    std::getline(_file, line);
    while (getline(_file, line)) {
        std::stringstream ss(line);
        std::string date, rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, ',');
        _data[date] = atof(rate.c_str());
    }
    return _data;
}

void inputChecker(char* filename, std::map<std::string, double> _data);

bool checkDateValid(const std::string& date);

bool checkValueValid(const std::string& value);

double getRate(std::string date, std::map<std::string, double> data);

std::string getDayBefore(std::string& date);

std::string intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void inputChecker(char* filename, std::map<std::string, double> _data) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: The file provided can't be opened." << std::endl;
        exit(1);
    }
    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != "date | value") {
        std::cerr << "Error: The first line of the file provided doesn't follow the 'date | value' - format " << std::endl;
        exit(1);
    }
    std::string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value;
        char separator;
        if (!(iss >> date >> separator >> value) || separator != '|') {
            std::cout << "Error: bad input => " << date << std::endl;
        }
        else if (!checkDateValid(date) || !checkValueValid(value));
        else if (atof(value.c_str()) >= 0 || atof(value.c_str()) <= 1000) {
            double prod = atof(value.c_str()) * getRate(date, _data);
            std::cout << date << " => " << value << " = " << prod << std::endl;
        }
        else
            std::cout << "Error: bad input => " << date << std::endl;

    }
    inputFile.close();
}

bool checkDateValid(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        std::cout << "Error: Wrong Date-Time Format" << std::endl;
        return false;
    }

    int year;
    int month;
    int day;
    char separator1;
    char separator2;
    std::istringstream ss(date);
    ss >> year >> separator1 >> month >> separator2 >> day;

    if (!ss || (separator1 != '-' || separator2 != '-')) {
        std::cout << "Error: Date-format is wrong" << std::endl;
        return false;
    }
    if (date.size() != 10)
        std::cout << "Error: Date-format is wrong: too short or too long!" << std::endl;
    else if (!ss || (separator1 != '-' || separator2 != '-'))
        std::cout << "Error: Date-format is wrong" << std::endl;
    else if ((year < 2009 || (day < 2 && month == 1 && year == 2009)) || (year == 2022 && day > 29 && month == 3))
        std::cout << "Error: No Data found for this Date" << std::endl;
    else if ((month < 1 || month > 12) || (day < 1 || day > 31))
        std::cout << "Error: Not a Valid Date format" << std::endl;
    else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && day < 30)
        std::cout << "Error: April, June, September, and November only have 30 days!" << std::endl;
    else if (!(year % 4 == 0) && month == 2 && day > 28)
        std::cout << "Error: Date not Valid: Not a leap year" << std::endl;
    else
        return true;
    return false;
}

bool checkValueValid(const std::string& value) {
    double val = atof(value.c_str());
    if (val < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else if (val > 1000)
        std::cout << "Error: too large a number." << std::endl;
    else
        return true;
    return false;
}

double getRate(std::string date, std::map<std::string, double> data) {
    std::map<std::string, double>::iterator it = data.find(date);
    if (it != data.end())
        return it->second;
    else {
        std::string dayBefore = getDayBefore(date);
        if (dayBefore.compare("not valid date") == 0) {
            return 0;
        }
        return getRate(dayBefore, data);
    }
}

std::string getDayBefore(std::string& date) {
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    int prev_day = day - 1;
    int prev_month = month;
    int prev_year = year;
    if (prev_day == 0) {
        prev_month = month - 1;
        if (prev_month == 0) {
            prev_month = 12;
            prev_year = year - 1;
            if (prev_year < 2009) {
                return "not a valid date";
            }
        }
        switch (prev_month) {
            case 2:
                if (prev_year % 4 == 0) {
                    prev_day = 29;
                } else {
                    prev_day = 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                prev_day = 30;
                break;
            default:
                prev_day = 31;
        }
    }
    std::string prev_date = intToString(prev_year) + "-";
    if (prev_month < 10)
        prev_date += "0" + intToString(prev_month);
    else
        prev_date += intToString(prev_month);
    if (prev_day < 10)
        prev_date += "-0" + intToString(prev_day);
    else
        prev_date += "-" + intToString(prev_day);
    return (prev_date);
}