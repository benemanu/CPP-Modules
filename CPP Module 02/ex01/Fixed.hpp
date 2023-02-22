#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>

class Fixed
{
    private: 
        int fixed_point_value;
        static const int fractional_bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &copy);
        Fixed(const int integer);
        Fixed(const float floating_point);
        ~Fixed();
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif