#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ios>

class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException() : std::runtime_error("error: Invalid Input\n") { }
    virtual const char* what() const throw() {
        return std::runtime_error::what();
    }
};

std::map<std::string, double> readFile();
void inputChecker(char* filename, std::map<std::string, double> _data);
double getRate(std::string date, std::map<std::string, double> data);
std::string getDayBefore(std::string& date);
bool checkValueValid(const std::string &value);
bool checkDateValid(const std::string &date);

#endif