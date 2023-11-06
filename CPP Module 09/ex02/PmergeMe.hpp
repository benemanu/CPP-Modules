#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>
#include <sstream>

void checkInput(int argc, char **argv, bool flag, std::string choice, int tmp);
int checkInputValid(const char *input);

class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException() : std::runtime_error("error: Invalid Input") { }
    virtual const char* what() const throw() {
        return std::runtime_error::what();
    }
};
#endif