#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign)
{
    (void)assign;
    return *this;
}

void ScalarConverter::convert(std::string input) 
{
    static char _char = '\0';
    static int _int = 0;
    static double _double = 0.0;
    static float _float = 0.0;
    std::istringstream sstream(input);
    int _type = getType(input);

    switch (_type) {
        case CHAR:
            _char = input[0]; 
            _int = static_cast<int>(_char);
            _float = static_cast<float>(_char);
            _double = static_cast<double>(_char);
            printAll(&_char, &_int, &_double, &_float, input, _type);
            break;
        case INT:
            sstream >> _int;
            _char = static_cast<char>(_int);
            _float = static_cast<float>(_int);
            _double = static_cast<double>(_int);
            printAll(&_char, &_int, &_double, &_float, input, _type);
            break;
        case FLOAT:
            sstream >> _float;
            _char = static_cast<char>(_float);
            _int = static_cast<int>(_float);
            _double = static_cast<double>(_float);
            printAll(&_char, &_int, &_double, &_float, input, _type);
            break;
        case DOUBLE:
            sstream >> _double;
            _char = static_cast<char>(_double);
            _int = static_cast<int>(_double);
            _float = static_cast<float>(_double);
            printAll(&_char, &_int, &_double, &_float, input, _type);
            break;
        default:
            break;
    }
}

bool ScalarConverter::isChar (std::string _str) {
    return _str.length() == 1 && std::isalpha(_str[0]) && std::isprint(_str[0]);
}

bool ScalarConverter::isInt (std::string _str) {
    int i = 0;
    if (_str[i] == '+' || _str[i] == '-') {
        i++;
    }
    for (int j (i); j < (int) _str.length(); j++) {
        if (!std::isdigit(_str[j])) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isDouble (std::string _str) {
   if ( _str.find( '.' ) == std::string::npos || _str.find( '.' ) == 0 
        || _str.find( '.' ) == _str.length() - 1 )
        return false;
    int i = 0;
    int found = 0;
    if (_str[i] == '-' || _str[i] == '+') {
        i++;
    }
    for (int j (i); j < (int) _str.length(); j++) {
        if (_str[j] == '.') {
            found++;
        }
        if (!std::isdigit(_str[j]) && ((_str[j] != '.') || found > 1)) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isFloat(std::string _str) {
    if ( _str.find( '.' ) == std::string::npos || _str[_str.length() - 1] != 'f' 
        || _str.find( '.' ) == 0 || _str.find( '.' ) == _str.length() - 2 )
        return false;
    int found = 0;
    int i = 0;
    if ( _str[i] == '-' || _str[i] == '+' )
        i++;
    for ( int j (i) ; j < ( int ) _str.length() - 1; j++ ) {
        if ( _str[j] == '.' )
            found++;
        if ( ( !std::isdigit( _str[j] ) && _str[j] != '.' ) || found > 1 )
            return false;
    }

    return true;
}

bool ScalarConverter::isLiterals(std::string _str) {
    if ((_str.compare("nan") == 0) || (_str.compare("-inf") == 0) || (_str.compare("+inf") == 0) 
    || (_str.compare("-inff") == 0) || (_str.compare("+inff") == 0) || (_str.compare("nanf") == 0)) {
        return true;
    }
    return false;
}

bool ScalarConverter::isLiteralsFloat(std::string _str) {
    if ((_str.compare("nanf") == 0) || (_str.compare("-inff") == 0) || ( (_str.compare("+inff") == 0))) {
        return true;
    }
    return false;
}

bool ScalarConverter::isLiteralsDouble(std::string _str) {
    if ((_str.compare("nan") == 0) || (_str.compare("-inf") == 0) || ( (_str.compare("+inf") == 0))) {
        return true;
    }
    return false;
}


int ScalarConverter::getType(std::string input)
{
    if (ScalarConverter::isInt(input)) {
        return 1;
    }
    else if (ScalarConverter::isFloat(input)) {
        return 2;
    }
    else if (ScalarConverter::isChar(input)) {
        return 3;    
    }
    else if (ScalarConverter::isDouble(input)) {
        return 4;
    }
    else if (ScalarConverter::isLiteralsFloat(input)) {
        return 2;
    }
    else if (ScalarConverter::isLiteralsDouble(input)) {
        return 4;
    }
    else {
        return 0;
    }
}

void ScalarConverter::printAll(char *_char, int *_int, double *_double, float *_float, std::string input, int _type) {
    ScalarConverter::printChar(*_char, input);
    ScalarConverter::printInt(*_int, input);
    ScalarConverter::printFloat(*_float, input, _type);
    ScalarConverter::printDouble(*_double, input, _type);
}

void ScalarConverter::printInt(int _int, std::string _str) {
    if (isLiterals(_str) || (!std::isprint(_int) && (_int >= 127))) {
    std::cout << "int: impossible";
    } else {
        std::cout << "int: " << _int;
    }
    std::cout << std::endl;
}


void ScalarConverter::printChar(char _char, std::string _str) {
    if (isLiterals(_str) || (!std::isprint(_char) && (_char >= 127))) {
        std::cout << "char: impossible";
    } else if (!std::isprint(_char)) {
        std::cout << "char: Non displayable";
    } else {
        std::cout << "char: '" << _char << "'";
    }
    std::cout << std::endl;
}

void ScalarConverter::printFloat(float _float, std::string _str, int _type) {
   if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "float: nanf";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "float: +inff";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "float: -inff";
    } else if ( isImpossible(_str, _type) ) {
        std::cout << "float: impossible";
    } else { 
        if (_float - static_cast<int>(_float) == 0) {
            std::cout << "float: " << _float << ".0f";
        } else {
            std::cout << "float: " <<_float << "f";
        }
    }
    std::cout << std::endl;
}

void    ScalarConverter::printDouble(double _double, std::string _str , int _type) {
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "double: nan";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "double: +inf";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "double: -inf";
    } else if ( isImpossible(_str, _type) ) {
        std::cout << "double: impossible";
    } else {
        if ( _double - static_cast< int > ( _double ) == 0 ) {
            std::cout << "double: " << _double << ".0";
        } else {
            std::cout << "double: " << _double << "f";
        }
    }
    std::cout << std::endl;

}

bool ScalarConverter::isImpossible(std::string _str, int _type) {
    int _int;
    float _float;
    double _double;
    std::istringstream sstream(_str);
    try {
        if (_type == INT) {
            sstream >> _int;
        }
        else if (_type == FLOAT) {
            sstream >> _float;
        }
        else if (_type == DOUBLE) {
            sstream >> _double;
        }
    }
    catch (std::exception& e)
    {
        return true;
    }
    return false;
}