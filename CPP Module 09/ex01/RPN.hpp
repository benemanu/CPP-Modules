#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <sstream>

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

class InvalidInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Input \n";
    }
};

class InvalidStackException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack still has more than 1 value at the End \n";
    }
};

#endif