#include "RPN.hpp"

rpn::rpn() {}

rpn::rpn(const rpn &copy) {
    this->operator=(copy);
}

rpn::~rpn() {}

rpn&rpn::operator=(const rpn &assign) {
    (void)assign;
    return (*this);
}

void checkInput(std::string input) {
    std::stack<int> _stack;
    char op = 0;
    int nb = 0;
    int transform;
    for (size_t i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
                transform = atoi(&input[i]);
                _stack.push(transform);
        }
        else if (isOperator(input[i])) {
            op = input[i];
            if (_stack.size() > 1) {
                nb = _stack.top();
                _stack.pop();
                _stack.top() = calculateRpn(_stack.top(), nb, op);
            }  
        }
        else if (isspace(input[i])) {}
        else 
            throw InvalidInputException();
    }
    if (_stack.size() != 1)
        throw InvalidStackException();
    else
        std::cout << _stack.top() << std::endl;
}

int calculateRpn(int operand1, int operand2, char operatorr) {
    if (operatorr == '+')
        return (operand1 + operand2);
    else if (operatorr == '-')
        return (operand1 - operand2);
    else if (operatorr == '*')
        return (operand1 * operand2);
    else if (operatorr == '/') {
        if (operand2 == 0)
            throw std::runtime_error("You cant devide by zero");
        else
            return (operand1 / operand2);
    }
    else {
        std::ostringstream errorMsg;
        errorMsg << "Invalid Operator: " << operatorr;
        throw std::runtime_error(errorMsg.str());
    }
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}