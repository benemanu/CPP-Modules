#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>
#include <cmath>
#include <ctime>
#include <iomanip>

class InvalidInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The Input";
    }
};

std::map<std::string, double> readFile();
void inputChecker(std::string filename, std::map<std::string, double> _data);
double getRate(std::string date, std::map<std::string, double> data);
std::string getDayBefore(std::string& date);
bool checkValueValid(const std::string &value);
bool checkDateValid(const std::string &date);
bool findDate(std::string& date, std::map<std::string, double> data);

#endif