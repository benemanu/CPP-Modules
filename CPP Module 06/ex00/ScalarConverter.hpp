#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

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
        char        _char;
        int         _int;
        float       _float;
        double      _double;
        bool        _impossible;
        std::string _str;
        e_type      _type;


    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter &assignOperator);

        char getChar() const;
        void setChar(char c);

        int getInt() const;
        void setInt(int i);

        double getDouble() const;
        void setDouble(double d);

        float getFloat() const;
        void setFloat(float f); 

        e_type getType() const;

        bool isChar() const;
        bool isInt() const;
        bool isDouble() const;
        bool isFloat() const;
        bool isLiterals() const;
        bool isImpossible();

        void setStr(std::string str);
        void setType();
        void convert ();
        void printChar() const;
        void printInt() const;
        void printDouble() const;
        void printFloat() const;

        std::string getStr() const;

        class ConverterException : public std::exception {
        virtual const char* what() const throw() { return "Unknown type"; }
    };
};

std::ostream& operator<<( std::ostream& out, const ScalarConverter& rhs );



#endif