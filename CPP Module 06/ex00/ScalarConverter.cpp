#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &assign)
{
	if (this != &assign) {
        this->_char = assign.getChar();
        this->_int = assign.getInt();
        this->_float = assign.getFloat();
    }
    return *this;
}

bool ScalarConverter::isLiterals() const {
    if ((_impossible ) || (_str.compare("nan") == 0) || (_str.compare("-inf") == 0) || (_str.compare("+inf") == 0) 
    || (_str.compare("-inff") == 0) || (_str.compare("+inff") == 0) || (_str.compare("nanf") == 0)) {
        return true;
    }
    return false;
}

char ScalarConverter::getChar() const {
    return this->_char;
}

void ScalarConverter::setChar(char c) {
    this->_char = c;
}

void ScalarConverter::printChar() const {
    if (this->isLiterals() || (!std::isprint(_int) && (_int >= 127))) {
        std::cout << "impossible";
    } else if (!std::isprint(this->_int)) {
        std::cout << "Non displayable";
    } else {
        std::cout << "'" << getChar() << "'";
    }
    std::cout << std::endl;
}

int ScalarConverter::getInt() const {
    return this->_int;
}

void ScalarConverter::setInt(int i) {
    this->_int = i;
}

void ScalarConverter::printInt() const {
    if (this->isLiterals() || (!std::isprint(_int) && (_int >= 127))) {
    std::cout << "impossible";
    } else {
        std::cout << getInt();
    }
    std::cout << std::endl;
}

double ScalarConverter::getDouble() const {
    return this->_double;
}

void ScalarConverter::setDouble(double d) {
    this->_double = d;
}

float ScalarConverter::getFloat() const {
    return this->_float;
}

void ScalarConverter::setFloat(float f) {
    this->_float = f;
}

std::string ScalarConverter::getStr() const {
    return this->_str;
}

void ScalarConverter::setStr(std::string str) {
    this->_str = str; 
    this->setType();
    if ( getType() == NONE ) {
        throw ScalarConverter::ConverterException();
    }
}

e_type ScalarConverter::getType () const {
    return this->_type;
}

bool ScalarConverter::isChar () const {
    return _str.length() == 1 && std::isalpha(_str[0]) && std::isprint(_str[0]);
}

bool ScalarConverter::isInt () const {
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

bool ScalarConverter::isDouble () const {
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

bool ScalarConverter::isFloat() const {
    if ( _str.find( '.' ) == std::string::npos || _str.back() != 'f' 
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

bool ScalarConverter::isImpossible() {
    try {
        if (_type == INT) {
            _int = std::stoi(_str);
        }
        else if (_type == FLOAT) {
            _float = std::stof(_str);
        }
        else if (_type == DOUBLE) {
            _double = std::stod(_str);
        }
    }
    catch (std::exception& e)
    {
        _impossible = true;
        return true;
    }
    return false;
}

void ScalarConverter::setType() {
    if (isChar()) {
        _type = CHAR;
    }
    else if (isInt()) {
        _type = INT;
    }
    else if (isFloat()) {
        _type = FLOAT;
    }
    else if (isDouble()) {
        _type = DOUBLE;
    }
    else if (isLiterals()) {
        _type = LITERALS;
    }
    else {
        _type = NONE;
    }
}

void ScalarConverter::printFloat() const {
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nanf";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inff";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inff";
    } else if ( _impossible ) {
        std::cout << "i mpossible";
    } else { 
        if (_float - static_cast<int>(_float) == 0) {
            std::cout << _float << ".0f";
        } else {
            std::cout << getFloat() << "f";
        }
    }
    std::cout << std::endl;
}

void    ScalarConverter::printDouble( void ) const {
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nan";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inf";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inf";
    } else if ( _impossible ) {
        std::cout << "impossible";
    } else {
        if ( _double - static_cast< int > ( _double ) == 0 ) {
            std::cout << _double << ".0";
        } else {
            std::cout << getDouble() << "f";
        }
    }
    std::cout << std::endl;

}

void ScalarConverter::convert() {
    if (isImpossible())
        return;
    switch (_type) {
        case CHAR:
            _char = _str[0];
            _int = static_cast<int>(_char);
            _float = static_cast<float>(_char);
            _double = static_cast<double>(_char);
            break;
        case INT:
            _int = std::stoi(_str);
            _char = static_cast<char>(_int);
            _float = static_cast<float>(_int);
            _double = static_cast<double>(_int);
            break;
        case FLOAT:
            _float = std::stof(_str);
            _char = static_cast<char>(_float);
            _int = static_cast<int>(_float);
            _double = static_cast<double>(_float);
            break;
        case DOUBLE:
            _double = std::stod(_str);
            _char = static_cast<char>(_double);
            _int = static_cast<int>(_double);
            _float = static_cast<float>(_double);
            break;
        default:
            break;
    }
}

std::ostream&    operator<<( std::ostream& out, const ScalarConverter& rhs ) {
    out << "char: "; rhs.printChar();
    out << "int: "; rhs.printInt();
    out << "float: "; rhs.printFloat();
    out << "double: "; rhs.printDouble();
    return out;
}

