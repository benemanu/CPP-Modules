#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stdlib.h>


class rpn {
    private: 

    public: 
        rpn();
        rpn(const rpn &copy);
        ~rpn();
        rpn &operator=(const rpn &assign);
};
        void checkInput(std::string input);
        int calculateRpn(int operand1, int operand2, char operatorr);
        bool isOperator(char c);

class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException() : std::runtime_error("error: Invalid Input \n") { }
    virtual const char* what() const throw() {
        return std::runtime_error::what();
    }
};


class InvalidStackException : public std::runtime_error {
public:
    InvalidStackException() : std::runtime_error("error: Stack still has more than 1 value at the End \n") { }
    virtual const char* what() const throw() {
        return std::runtime_error::what();
    }
};

class InvalidInputTooBigException : public std::runtime_error {
public:
    InvalidInputTooBigException() : std::runtime_error("error: Invalid Input, only single digit numbers are allowed \n") { }
    virtual const char* what() const throw() {
        return std::runtime_error::what();
    }
};

#endif