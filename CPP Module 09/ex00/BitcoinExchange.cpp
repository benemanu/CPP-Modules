#include "BitcoinExchange.hpp"

std::map<std::string, double> readFile() {
    std::map<std::string, double> _data;
    std::ifstream _file("data.csv");
    std::string line;

    std::getline(_file, line);
    while (getline(_file, line)) {
        std::stringstream ss(line);
        std::string date, rate;
        std::getline(ss, rate, ',');
        std::getline(ss, date, ',');
        _data[date] = std::stod(rate);
    }
    return _data;
}



void inputChecker(std::string filename, std::map<std::string, double> _data) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: The file provided can't be opened." << std::endl;
        exit(1);
    }
    // std::cout << "File opened" << std::endl;
    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (!firstLine.compare("data | value")) {
        std::cerr << "Error: The first line of the file provided doesent follow the 'date | value' - format " << std::endl;
        exit(1);
    }
    std::string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value;
        char seperator;
        if (!(iss >> date >> seperator >> value) || seperator != '|') {
            std::cout << "Error: bad input => " << date << std::endl;
        }
        else if (!(checkDateValid(date)) || !(checkValueValid(value))) ;
        else if (stod(value) >= 0 || stod(value) <= 1000) { 
            double prod = stod(value) * getRate(date, _data);
            std::cout << date << " => " << value << " = " << prod << std::endl; 
        }
        else
            std::cout << "Error: bad input => " << date << std::endl;
    
    }
    inputFile.close();
}

bool checkDateValid(const std::string& date) {
    int year;
    int month;
    int day;
    char seperator;
    std::istringstream ss(date);
    ss >> year >> seperator >> month >> seperator >> day;
    if (date.size() != 10)
        std::cout << "Error: Date-format is worng: too short or too long!" << std::endl;
    else if (!ss || seperator != '-')
        std::cout << "Error: Date-format is wrong" << std::endl;
    else if ((year < 2009 || (day < 02 && month == 01 && year == 2009)) || (year = 2022 && day > 29 && month == 03))
        std::cout << "Error: No Data found for this Date" << std::endl;
    else if ((month < 01 || month > 12) || (day < 01 || day > 31))
        std::cout << "Error: Not a Valid Date format" << std::endl;
    else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && day < 30) 
        std::cout << "Error: April, June, September and November only have 30 days!" << std::endl;
    else if (!(year % 4 == 0) && month == 02 && day > 28) 
        std::cout << "Error: Date not Valid: Not a leap year" << std::endl;
    else 
        return true;
    return false;
}

bool checkValueValid(const std::string& value) {
    try {
        std::stof(value);
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    if (std::stod(value) < 0 ) 
        std::cout << "Error: not a positive number." << std::endl;
    else if (std::stod(value) > 1000)
        std::cout << "Error: too large a number." << std::endl;
    else
        return true;      
    return false;
}

double getRate(std::string date, std::map<std::string, double> data) {
    std::cout << date << std::endl;
    std::map<std::string, double>::iterator it = data.find(date);
    if (it != data.end()) {
        std::cout << it->second << std::endl;
        return it->second;
    }
    else {
        std::string dayBefore = getDayBefore(date);
        std::cout << dayBefore << std::endl;
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
                return "not valid date";
            }
        }
        switch (prev_month) {
            case 2:
                if (prev_year % 4 == 0 && (prev_year % 100 != 0 || prev_year % 400 == 0)) {
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
    std::string prev_date = std::to_string(prev_year) + "-";
    if (prev_month < 10)
        prev_date += "0" + std::to_string(prev_month);
    else
        prev_date += std::to_string(prev_month);
    if (prev_day < 10)
        prev_date += "-0" + std::to_string(prev_day);
    else
        prev_date += "-" + std::to_string(prev_day);
    return (prev_date);
}