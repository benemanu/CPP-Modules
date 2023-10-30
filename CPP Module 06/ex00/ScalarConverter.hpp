#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <sstream>

enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class ScalarConverter {
    private:
            ScalarConverter();
            ScalarConverter(const ScalarConverter &copy);
            ScalarConverter &operator=(const ScalarConverter &assign);
            static int getType(std::string input);
            static void printAll(char *_char, int *_int, double *_double, float *_float, std::string input, int _type);
           

    public:
            ~ScalarConverter();
            static void convert(std::string input);
            static bool isImpossible(std::string _str, int _type);
            static bool isChar(std::string _str);
            static bool isInt(std::string _str);
            static bool isDouble(std::string _str);
            static bool isFloat(std::string _str);
            static bool isLiterals(std::string _str);
            static bool isLiteralsDouble(std::string _str);
            static bool isLiteralsFloat(std::string _str);
            static void printDouble(double _double, std::string _str, int _type);
            static void printFloat(float _float, std::string _str, int _type);
            static void printChar(char _char, std::string _str);
            static void printInt(int _int, std::string _str);

};

std::ostream& operator<<( std::ostream& out, const ScalarConverter& rhs );



#endif